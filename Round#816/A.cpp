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

// Свойство пропорции a*d == b*c

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		int _min = min(n, m);
		int _max = max(n, m);
		if(_min == 1 && _max == 1)
			cout << 0 << '\n';
		else if(_min == 1)
			cout << _max << '\n';
		else
			cout << (_min << 1) - 1 + _max - 1 << '\n';
	}

	return 0;
}
