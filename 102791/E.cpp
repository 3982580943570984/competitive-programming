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
	vector<int> a(n);
	for(int i{0}; i < n; ++i) a[i] = i+1;

	cout << 2 << '\n';
	while (a.size() > 2) {
		int last = *(a.end() - 1);
		int _last = *(a.end() - 3);
		a.erase(a.end() - 3, a.end());
		a.push_back(ceil((_last + last)/2));
		cout << _last << ' ' << last << '\n';
		cout << (_last + last) / 2 << ' ' << (_last + last) / 2 << '\n';
	}
	
	cout << *a.begin() << ' ' << *(a.end()-1) << '\n';

	return 0;
}

