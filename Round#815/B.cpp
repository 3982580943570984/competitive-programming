#include <float.h>
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

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for(auto& value : a) cin >> value;
		sort(all(a));

		cout << a[n-1] - a[0] + a[n-2] - a[1] << '\n';
	}

	return 0;
}
