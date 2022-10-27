#include <cstdint>
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

struct node { int sum, pref, suff, ans; };
struct segTree {
	int size = 1;
	vector<node> tree;

	node leafNode(int value) { int _max = max(value, 0LL); return { value, _max, _max, _max }; }
	node combine(node& left, node& right) {
		return {
			left.sum + right.sum,
			max(left.pref, left.sum + right.pref),
			max(right.suff, right.sum + left.suff),
			max({ left.ans, right.ans, left.suff + right.pref })
		};
	}

	void initialize(int n) {
		while(size < n) size <<= 1;
		tree.assign((size << 1) - 1, node{0, 0, 0, 0});
	}

	void build_max(vector<int>& a) { initialize(a.size()); build_max(a, 0, 0, size); };
	void build_max(vector<int>& a, int x, int lx, int rx) {
		if(rx == lx+1) {
			if(lx < a.size())
				tree[x] = leafNode(a[lx]);
		} else {
			int m = (lx + rx) >> 1;
			build_max(a, (x << 1) + 1, lx, m);
			build_max(a, (x << 1) + 2, m, rx);
			tree[x] = combine(tree[(x << 1) + 1], tree[(x << 1) + 2]);
		}
	};

	void set_max(int index, int value) { set_max(index, value, 0, 0, size); };
	void set_max(int index, int value, int x, int lx, int rx) {
		if(rx == lx+1) { tree[x] = leafNode(value); return; }
		int m = (lx+rx) >> 1;
		index < m ? set_max(index, value, (x << 1) + 1, lx, m) : set_max(index, value, (x << 1) + 2, m, rx);
		tree[x] = combine(tree[(x << 1) + 1], tree[(x << 1) + 2]);
	};

};

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	vector<int> a(n);
	for(auto& num : a) cin >> num;

	segTree sgt;
	sgt.build_max(a);

	cout << sgt.tree[0].ans << '\n';
	for(int i{0}; i < m; ++i) {
		int index, value; cin >> index >> value;
		sgt.set_max(index, value);
		cout << sgt.tree[0].ans << '\n';
	}

	return 0;
}

