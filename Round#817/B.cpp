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

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string first, second; cin >> first >> second;
		for (int i{0}; i < n; ++i) {
			if (first[i] == 'G') first[i] = 'B';
			if (second[i] == 'G') second[i] = 'B';
		}
		first == second ? cout << "YES" << '\n' : cout << "NO" << '\n';
	}

	return 0;
}

