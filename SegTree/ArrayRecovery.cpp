#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>

#define int long long
using namespace std;

vector<int> a;
void build (vector<int>& tree, int v, int l, int r) {
	if (l == r) { tree[v] = a[l]; return; }
	int m = (l + r) / 2;
	build(tree, v * 2, l, m);
	build(tree, v * 2 + 1, m + 1, r);
	tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
}

int query (vector<int>& tree, int v, int l, int r, int ql, int qr) {
	if (l > qr || r < ql) return 2147483648;
	if (l >= ql && r <= qr) return tree[v];
	int m = (l + r) / 2;
	return min(query(tree, v * 2, l, m, ql, qr), query(tree, v * 2 + 1, m + 1, r, ql, qr));
}

int32_t main () {
	/*
	freopen("rmq.in", "r", stdin);
	freopen("rmq.out", "w", stdout);
	*/
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n, m; cin >> n >> m;
	// ans, left, right
	vector<pair<int, pair<int, int>>> queries;
	a.resize(n);
	for (int i = 0; i < m; ++i) {
		int l, r, q; cin >> l >> r >> q;
		for (int j = l - 1; j < r; ++j) a[j] = q;
		queries.push_back({q, {l, r}});
	}
	for (auto e : a) cout << e << ' '; cout << endl;
	vector<int> tree(4*n);
	build(tree, 1, 0, n - 1);
	bool res = true;
	for (auto& [q, range] : queries) {
		cout << query(tree, 1, 0, n - 1, range.first - 1, range.second - 1) << ' ' << q << endl;
		if (query(tree, 1, 0, n - 1, range.first - 1, range.second - 1) != q) {
			res = false;
			break;
		}
	}
	if (res) {
		cout << "consistent" << endl;
		for (auto e : a) cout << e << ' ';
		cout << endl;
	} else {
		cout << "inconsistent" << endl;
	}
}
