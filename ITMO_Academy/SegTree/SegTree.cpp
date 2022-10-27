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

struct segTree {
	vector<int> tree; // Elements array
	int size{1}; // Max size of array

	void init(int n) {
		while(size < n) size <<= 1;
		tree.assign((size << 1) - 1, 0);
	}

	void build_sum(vector<int>& a) { init(a.size()); build_sum(a, 0, 0, size); }
	void build_sum(vector<int>& a, int x, int lx, int rx) {
		if(rx - lx == 1) {
			if(lx < a.size()) tree[x] = a[lx];
		} else {
			int m = (lx+rx) >> 1;
			build_sum(a, (x << 1) + 1, lx, m);
			build_sum(a, (x << 1) + 2, m, rx);
			tree[x] = tree[(x << 1) + 1] + tree[(x << 1) + 2];
		}
	}

	void build_min(vector<int>& a) { init(a.size()); build_min(a, 0, 0, size); }
	void build_min(vector<int>& a, int x, int lx, int rx) {
		if(rx - lx == 1) {
			if(lx < a.size()) tree[x] = a[lx];
		} else {
			int m = (lx+rx) >> 1;
			build_min(a, 2*x+1, lx, m);
			build_min(a, 2*x+2, m, rx);
			tree[x] = min(tree[(x << 1) + 1], tree[2*x+2]);
		}
	}

	void set_sum(int i, int v) { set_sum(i, v, 0, 0, size); }
	void set_sum(int i, int v, int x, int lx, int rx) {
		if(rx - lx == 1) { tree[x] = v; return;}
		int m = (lx+rx) >> 1;
		i < m ? set_sum(i, v, (x << 1) + 1, lx, m) : set_sum(i, v, (x << 1) + 2, m, rx);
		tree[x] = tree[(x << 1) + 1] + tree[(x << 1) + 2];
	}

	void set_min(int i, int v) { set_min(i, v, 0, 0, size); }
	void set_min(int i, int v, int x, int lx, int rx) {
		if(rx - lx == 1) { tree[x] = v; return; }
		int m = (lx+rx)/2;
		i < m ? set_min(i, v, 2*x+1, lx, m) : set_min(i, v, 2*x+2, m, rx);
		tree[x] = min(tree[2*x+1], tree[2*x+2]);
	}

	int sector_sum(int l, int r) { return sector_sum(l, r, 0, 0, size); }
	int sector_sum(int l, int r, int x, int lx, int rx) {
		if(l >= rx || lx >= r) return 0;
		if(lx >= l && rx <= r) return tree[x];
		int m = (lx+rx) >> 1;
		return (sector_sum(l, r, (x << 1) + 1, lx, m) + sector_sum(l, r, (x << 1) + 2, m, rx));
	}

	int sector_min(int l, int r) { return sector_min(l, r, 0, 0, size); }
	int sector_min(int l, int r, int x, int lx, int rx) {
		if(l >= rx || lx >= r) return INT64_MAX;
		if(lx >= l && rx <= r) return tree[x];
		int m = (lx + rx) / 2;
		return min(sector_min(l, r, 2*x + 1, lx, m), sector_min(l, r, 2*x + 2, m, rx));
	}

	void print() { for(auto& elem : tree) cout << elem << ' '; cout << '\n'; }	
};

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);

	segTree st;
	int n, m; cin >> n >> m;
	vector<int> a(n);
	for(auto& num : a) cin >> num;

	st.build_sum(a);

	for(int i{0}; i < m; ++i) {
		int c; cin >> c;
		int index, value; cin >> index >> value;
		if(c==1) st.set_sum(index, value);
		if(c==2) cout << st.sector_sum(index, value) << '\n';
	}

	return 0;
}

