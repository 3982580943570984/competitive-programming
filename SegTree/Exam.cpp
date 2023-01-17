#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>

#define int long long
using namespace std;

void set (vector<int>& tree, int v, int l, int r, int i, int val) {
	if (l == r) { tree[v] = val; cout << i << ' '; return; }
	int m = (l + r) >> 1;
	if (i <= m) {
		tree[v << 1] == 0
			? set(tree, v << 1, l, m, i, val)
			: set(tree, (v << 1) + 1, m + 1, r, m + 1, val);
	} else {
		set(tree, (v << 1) + 1, m + 1, r, i, val);
	}
	tree[v] = min(tree[v << 1], tree[(v << 1) + 1]);
}

void _set (vector<int>& tree, int v, int l, int r, int i, int val) {
	if (l == r) { tree[v] = val; return; }
	int m = (l + r) >> 1;
	i <= m
		? _set(tree, v << 1, l, m, i, val)
		: _set(tree, (v << 1) + 1, m + 1, r, i, val);
	tree[v] = min(tree[v << 1], tree[(v << 1) + 1]);
}

int32_t main () {
	/*
	freopen("exam.in", "r", stdin);
	freopen("exam.out", "w", stdout);
	*/
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n; cin >> n;
	vector<int> a(n); for (auto& e : a) cin >> e;
	vector<int> tree(4*n);
	for (auto e : a) {
		e < 0
			? _set(tree, 1, 0, n - 1, abs(e), 0)
			: set(tree, 1, 0, n - 1, e, 1);
	}
}
