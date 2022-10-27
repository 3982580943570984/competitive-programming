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
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	int _3{0};
	int _5{0};
	int _7{0};

	if(n-7 >= 0) {
		cout << (n-7) / 3 << 0 << 1;
	} else if(n - 5 >= 0) {	
		cout << (n-5) / 3 << 1 << 0;
	} else {
		n%3 == 1 ? cout << -1 << '\n' : cout << n/3 << 1 << 0;
	}

	return 0;
}
