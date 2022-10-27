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

	int n,k; cin >> n >> k;
	vector<int> a(n);
	for(int i{0}; i < n; ++i) cin >> a[i];
	sort(a.begin(), a.end());

	int l{1}; int r{2000000000};
	int m;
	int result{0};
	while(l <= r) {
		m = (l+r)/2;
		int actions{0};
		for(int i{n/2}; i < n; ++i) {
			if(m > a[i])
				actions += m - a[i];
			if(actions > k) {
				r = m - 1;
				break;
			}
		}

		if(actions <= k) {
			l = m + 1;
			result = m;
		}
	}
	cout << result << '\n';

	return 0;
}

