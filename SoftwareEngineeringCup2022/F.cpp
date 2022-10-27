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

using namespace std;

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k, d; cin >> n >> m >> k >> d;
	vector<int> a(n);
	for(int i{0}; i < n; ++i) cin >> a[i];
	vector<int> b(m);
	for(int i{0}; i < m; ++i) { int power; cin >> power; power += d; b[i] = power; }
	vector<int> c(k);
	for(int i{0}; i < k; ++i) cin >> c[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	int steps{0};
	for(int i{0}; i < m; ++i) {
		auto e1 = lower_bound(a.begin(), a.end(), b[i]);
		if(e1 != a.end()) {
			steps += 1;
			*e1 = 0;
			continue;
		}

		auto e2 = lower_bound(c.begin(), c.end(), b[i]);
		if(e2 != c.end()) {
			steps += 2;
			*e2 = 0;
			continue;
		}

		steps = -1;
		break;
	}
	
	cout << steps << '\n';

	return 0;
}

