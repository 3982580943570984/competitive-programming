#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iomanip>
#include <cmath>

#define int long long int

using namespace std;

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,m,k; cin >> n >> m >> k;
	vector<int> a(n);
	for(int i{0}; i < n; i++) cin >> a[i];

	vector<int> prefix;
	inclusive_scan(a.begin(), a.end(),back_inserter(prefix), plus<>(), 0LL);
	prefix.push_back(0);

	for (auto number:prefix) cout << number << ' ';
	cout << '\n';
	
	vector<pair<int, pair<int, int>>> operations;
	int l,r,d;
	for(int i{0}; i < n; i++) {
		cin >> l >> r >> d;
		--r; --l;
		operations.push_back(make_pair(d, make_pair(l, r)));
	}

	int x,y;
	for(int i{0}; i < k; ++i) {
		cin >> x >> y;
		int d, l, r, multiplier;
		for(int j{x-1}; j < y; j++) {
			d = operations[j].first;
			l = operations[j].second.first;
			r = operations[j].second.second;
			multiplier = r - l + 1;
			cout << "l: " << l << " r: " << r << " d: " << d << " multiplier: " << multiplier << '\n';
			prefix[r+1] -= prefix[l+1];
			prefix[r+1] += multiplier * d;
		}
	}

	for(int i{0}; i < n; i++) {
		cout << prefix[i] << ' ';
	}

	return 0;
}
