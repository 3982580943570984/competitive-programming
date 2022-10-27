#include <iostream>
#include <algorithm>
#include <iterator>
#include <limits.h>
#include <limits>
#include <numeric>
#include <stdint.h>
#include <type_traits>
#include <utility>
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

struct segTree_kth_unit {
	int tree_size{1};
	vector<int> tree;

	void initialize(int n) {
		while (tree_size < n) tree_size <<= 1;
		tree.assign((tree_size << 1) - 1, 0);
	}

	void build(vector<int>& a) { initialize(a.size()); build(a, 0, 0, tree_size); };
	void build(vector<int>& a, int x, int left, int right) {
		if(right - left == 1) {
			if(left < a.size())
				tree[x] = a[left];
		} else {
			int mid = (left + right) >> 1;
			build(a, (x << 1) + 1, left, mid);
			build(a, (x << 1) + 2, mid, right);
			tree[x] = max(tree[(x << 1) + 1], tree[(x << 1) + 2]);
		}
	};

	void update(int index, int value) { update(index, value, 0, 0, tree_size); };
	void update(int index, int value, int x, int left, int right) {
		if(right - left == 1) { tree[x] = value; return; }
		int mid = (left + right) >> 1;
		index < mid ? update(index, value, (x << 1) + 1, left, mid) : update(index, value, (x << 1) + 2, mid, right);
		tree[x] = max(tree[(x << 1) + 1], tree[(x << 1) + 2]);
	};

	int first_above(int value) { return first_above(value, 0, 0, tree_size); };
	int first_above(int value, int x, int left, int right) {
		if(tree[x] < value) { return -1; }
		if(right - left == 1) { return left; } // return index
		int mid = (left + right) >> 1;
		int result = first_above(value, (x << 1) + 1, left, mid);
		if(result == -1) result = first_above(value, (x << 1) + 2, mid, right);
		return result;
	};

	int first_above_index(int value, int index) { return first_above_index(value, index, 0, 0, tree_size); };
	int first_above_index(int value, int index, int x, int left, int right) {
		if(tree[x] < value) { return -1; }
		if(right <= index)  { return -1; }
		if(right - left == 1) { return left; }
		int mid = (left + right) >> 1;
		int result = first_above_index(value, index, (x << 1) + 1, left, mid);
		if(result == -1) result = first_above_index(value, index, (x << 1) + 2, mid, right);
		return result;
	};

	int find_kth(int k) { return find_kth(k, 0, 0, tree_size); };
	int find_kth(int k, int x, int left, int right) {
		if(right - left == 1) { return left; }
		int mid = (left + right) >> 1;
		if(k < tree[(x << 1) + 1])
			return find_kth(k, (x << 1) + 1, left, mid);
		else
			return find_kth(k - tree[(x << 1) + 1], (x << 1) + 2, mid, right);
	}

	void print() {
		for(auto& elem : tree) cout << elem << ' ';
		cout << '\n';
	}
};

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m; cin >> n >> m;
	
	vector<int> a(n);
	for(auto& elem : a) cin >> elem;
	
	segTree_kth_unit sgt;
	sgt.build(a);

	for(int i{0}; i < m; ++i) {
		int c; cin >> c;
		if(c == 1) { int index, value; cin >> index >> value; sgt.update(index, value); };
		if(c == 2) { int x, left; cin >> x >> left; cout << sgt.first_above_index(x, left) << '\n'; };
	}

	return 0;
}
