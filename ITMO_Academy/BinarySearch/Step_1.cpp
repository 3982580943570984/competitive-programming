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

bool find(vector<int>& a, int x) {
	int l = 0, r = a.size() - 1;
	int mid = (l+r) >> 1;
	while(r >= l) {
		mid = (l+r) >> 1;
		if(a[mid] == x) return true;
		if(a[mid] < x) l = mid + 1;
		if(a[mid] > x) r = mid - 1;
	}
	return false;
}

int find_lower(vector<int>& a, int x) {
	int l = -1, r = a.size();
	int mid = (l+r) >> 1;
	while(r > l + 1) {
		mid = (l+r) >> 1;
		if(a[mid] <= x)
			l = mid;
		else
			r = mid;
	}
	return l;
}

int find_upper(vector<int>& a, int x) {
	int l = -1, r = a.size();
	int mid = (l+r) >> 1;
	while(r > l + 1) {
		mid = (l+r) >> 1;
		if(a[mid] < x)
			l = mid;
		else
			r = mid;
	}
	return r;
}

bool solve(vector<int>& a, int x) {
	return *lower_bound(all(a), x) == x;
}

int solve(vector<int>& a, int l, int r) {
	int ans{0};
	int first = upper_bound(all(a), r) - a.begin();  //find_lower(a, r);
	int second = lower_bound(all(a), l) - a.begin(); //find_lower(a, l);
	//cout << first << ' ' << second << '\n';
	ans += first - second;
	//if(a[first] == r) ++ans;
	//if(a[second] == l) ++ans;
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n; cin >> n;
	vector<int> a(n);
	for(auto& elem : a) cin >> elem;

	sort(all(a));

	int k; cin >> k;
	while(k--) {
		int l, r; cin >> l >> r;
		cout << solve(a, l, r) << ' ';
		// find(a, x) ? cout << "YES\n" : cout << "NO\n";
		// solve(a, x) ? cout << "YES\n" : cout << "NO\n";
		// cout << find_lower(a, x) + 1 << '\n';
		// cout << find_upper(a, x) + 1 << '\n';
	}
	cout << '\n';

	return 0LL;
}
