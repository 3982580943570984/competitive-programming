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
		tree[x] = tree[(x << 1) + 1] + tree[(x << 1) + 2];
	};

	int sector_sum(int left, int right) { return sector_sum(left, right, 0, 0, tree_size); };
	int sector_sum(int left, int right, int x, int lx, int rx) {
		if(left >= rx || lx >= right) return 0;
		if(lx >= left && rx <= right) return tree[x];
		int mid = (lx + rx) >> 1;
		return (sector_sum(left, right, (x << 1) + 1, lx, mid) + sector_sum(left, right, (x << 1) + 2, mid, rx));
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

	int n; cin >> n;
	segTree_kth_unit sgt;
	sgt.initialize(n);

	for(int i{0}; i < n; ++i) {
		int index; cin >> index;
		cout << sgt.sector_sum(index, n) << ' ';
		sgt.update(index, 1);
	}
	cout << '\n';

	return 0;
}
