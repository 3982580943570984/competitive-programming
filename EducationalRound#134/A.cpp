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
		string first, second; cin >> first >> second;
		set<char> _set;
		_set.insert(first[0]); _set.insert(first[1]);
		_set.insert(second[0]); _set.insert(second[1]);
		cout << _set.size() - 1 << '\n';
	}

	return 0;
}

