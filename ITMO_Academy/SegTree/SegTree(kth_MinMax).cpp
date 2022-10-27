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

struct segTree_kth {
	vector<pair<int, int>> tree;
	int size;

	void init(int n) {
		size = 1;
		while (size < n) size *= 2;
		tree.assign(2*size - 1, make_pair(INT64_MAX, 1));
	}

	pair<int, int> combine_min(pair<int, int> a, pair<int, int> b) {
		if(a.first > b.first) return b;
		if(b.first > a.first) return a;
		return make_pair(a.first, a.second + b.second);
	}

	void build_min(vector<int>& a) {
		init(a.size());
		build_min(a, 0, 0, size);
	}
	void build_min(vector<int>& a, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < a.size())
				tree[x] = make_pair(a[lx], 1);
		} else {
			int m = (lx+rx) / 2;
			build_min(a, 2*x + 1, lx, m);
			build_min(a, 2*x + 2, m, rx);
			tree[x] = combine_min(tree[2*x + 1], tree[2*x + 2]);
		}
	}

	void set_min(int index, int value) { set_min(index, value, 0, 0, size); }
	void set_min(int index, int value, int x, int lx, int rx) {
		if(rx - lx == 1) {
			tree[x] = make_pair(value, 1);
			return;
		}
		int m = (lx+rx) / 2;
		index < m ? set_min(index, value, 2*x + 1, lx, m) : set_min(index, value, 2*x + 2, m, rx);
		tree[x] = combine_min(tree[2*x + 1], tree[2*x + 2]);
	}

	pair<int, int> sector_min(int left, int right) { return sector_min(left, right, 0, 0, size); }
	pair<int, int> sector_min(int left, int right, int x, int lx, int rx) {
		if(left >= rx || lx >= right) return make_pair(INT64_MAX, 0);
		if(lx >= left && rx <= right) return tree[x];
		int m = (lx+rx) / 2;
		return combine_min(sector_min(left, right, 2*x + 1, lx, m), sector_min(left, right, 2*x + 2, m, rx));
	}


	void print() {
		for(auto& pair : tree) cout << pair.first << ' ' << pair.second << '\n';
	}
};

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	segTree_kth st_kth;

	int n, m; cin >> n >> m;
	vector<int> a(n);
	for(auto& elem : a) cin >> elem;

	st_kth.build_min(a);

	for(int i{0}; i < m; ++i) {
		int c; cin >> c;
		if(c == 1) {
			int index, value; cin >> index >> value;
			st_kth.set_min(index, value);
		} else {
			int left, right; cin >> left >> right;
			pair<int, int> kth = st_kth.sector_min(left, right);
			cout << kth.first << ' ' << kth.second << '\n';
		}
	}

	return 0;
}

