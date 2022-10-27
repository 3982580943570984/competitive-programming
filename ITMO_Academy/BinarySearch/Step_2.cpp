#include <concurrencysal.h>
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

int pack_rect(int n, int w, int h) {
	int l = 0, r = 1, mid;
	while((r/w) * (r/h) <= n) r <<= 1;

	while(r > l+1) {
		mid = (l+r) >> 1;
		if((mid/w) * (mid/h) >= n)
			r = mid;
		else
			l = mid;
	}

	return r;
}

double ropes(int n, int k) {
	vector<int> a(n);
	for(auto& elem : a) cin >> elem;

	double l = 0, r = 1e7 + 1, mid;
	for(int i{0}; i < 100; ++i) {
		mid = (l+r) * .5;
		int amount{0};
		for(auto& elem : a) amount += elem / mid;

		if(amount >= k)
			l = mid;
		else
			r = mid;
	}

	return l;
}

int task_c(int n, int x, int y) {
	if(x > y) swap(x, y);
	int l{0}, r{n*y + 1}, mid;
	while(r > l+1) {
		mid = (l+r) >> 1;
		if(((mid/x) + ((mid - x)/y)) < n)
			l = mid;
		else
			r = mid;
	}

	return r;
}

double task_e(double c) {
	double l{0.0}, r{1e10+1}, mid;
	while(r > l + 1e-6) {
		mid = (l+r) * .5;
		if((mid*mid + sqrt(mid)) <= c)
			l = mid;
		else
			r = mid;
	}
	return r;
}

int task_f(string t, string p, vector<int>& a) {
	int l{0}, r = a.size(), mid;
	while(r > l+1) {
		mid = (l + r) >> 1;
		string _t{t};
		for(int i{0}; i < mid; ++i) { _t[a[i]-1] = '-'; }

		int count{0};
		for(int i{0}, j{0}; i < p.size(); ++i) {
			for(; j < _t.size(); ++j) {
				if(_t[j] == '-') continue;
				if(_t[j] == p[i]) {
					++count;
					++j;
					break;
				}
			}
			if(count == p.size()) break;
		}

		// cout << count << ' ' << _t << ' ' << p << '\n';

		if(count == p.size())
			l = mid;
		else
			r = mid;
	}
	return l;
}

void task_d(int m, vector<vector<int>>& a) {
	int l{0}, r{1e8}, mid;
	while(r > l+1) {
		mid = (l+r) >> 1;
		int count{0};
		for(int i{0}; i < 
	}
};

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int m, n; cin >> m >> n;
	vector<vector<int>> a(n, vector<int>(4));
	for(int i{0}; i < n; ++i) { int t, z, y; cin >> t >> z >> y; a[i][0] = t; a[i][1] = z; a[i][2] = y; }

	task_d(m, a);

	return 0LL;
}
