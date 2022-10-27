#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iomanip>
#include <cmath>

#define int long long int
#define all(x) (x).begin(), x.end()

const int mod = (int) 1e9 + 7;

using namespace std;


vector<int> tree;
void build (vector<int>& a, int l, int r, int pos = 1) {
	if(l == r) {
		tree[pos] = a[l];
		return ;
	}
	int mid = (l + r) / 2;
	build(a, l, mid, pos*2);
	build(a, mid + 1, r, pos*2 + 1);
	tree[pos] = tree[pos*2] + tree[pos*2 + 1];
}

int sum (int l, int r, int tree_l, int tree_r, int pos = 1) {
	if(l > r) return 0;
	if(l == tree_l && r == tree_r) return tree[pos];
	int mid = (tree_l + tree_r) / 2;
	return sum(l, min(r, mid), tree_l, mid, pos*2) 
		+ sum(max(l, mid + 1), r, mid + 1, tree_r, pos*2 + 1);
}

void update (int index, int new_val, int tree_l, int tree_r, int pos = 1) {
	if(tree_l == tree_r) {
		tree[pos] = new_val;
		return;
	}
	int mid = (tree_l + tree_r) / 2;
	if(index <= mid)
		update(index, new_val, tree_l, mid, pos*2);
	else
		update(index, new_val, mid + 1, tree_r, pos*2 + 1);
	tree[pos] = tree[pos*2] + tree[pos*2 + 1];
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m; cin >> n >> m;
	tree.assign(4*n, 0);

	for(int i{0}; i < m; ++i) {
		int l, r, x;

	}

	return 0;
}
