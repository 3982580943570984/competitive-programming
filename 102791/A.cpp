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
	int r, y, b; cin >> r >> y >> b;

	int _max = max(r, max(y, b));
	int _min = min(r, min(y, b));
	int _med = r + y + b - _max - _min;

	int count{0};
	while(true) {
		if(n - _min >= 0) {
			++count;
			n -= _min;
		} else break;

		if(n - _med >= 0) {
			++count;
			n -= _med;
		} else break;

		if(n - _max >= 0) {
			++count;
			n -= _max;
		} else break;
	}

	cout << count << '\n';

	return 0;
}
