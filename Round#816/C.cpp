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

int solve(vector<pair<int, int>>& a, int index) {
	return 0;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	vector<pair<int, int>> a(n, make_pair(0, 0));
	for(auto& num : a) cin >> num.first;

	a[n-1].second = 1;
	for(int i{n-2}; i >= 0; ++i) {
		a[i].first == a[i+1].first ? a[i].second = a[i+1].second + 1 : a[i+1].second << 1;
	}

	for(int i{0}; i < m; ++i) {
		int index, value; cin >> index >> value;
		a[index-1].first = value;
		cout << solve(a, index) << '\n';
	}

	return 0;
}

