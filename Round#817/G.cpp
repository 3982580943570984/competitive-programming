#include <cstdint>
#include <float.h>
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

int32_t main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);

	int t; std::cin >> t;
	while (t--) {
		int n; std::cin >> n;
		std::vector<int> a;
		std::vector<int> b;
		
		if (n & 1) {
			a.assign((n >> 1) + 1, 0); b.assign(n >> 1, 0);
			for(int i{0}; i < (n >> 1); ++i) { a[i+1] = b[i] = i + 1; }
		} else {
			a.assign(n >> 1, 0); b.assign(n >> 1, 0);
			for(int i{0}; i < (n >> 1); ++i) { a[i] = b[i] = i + 1; }
		}

		//for(auto& elem : a) std::cout << elem << ' ';
		//std::cout << '\n';
		
		if (((n + 1) >> 1) & 1) {
			for(int i{0}; i < a.size() - 1; ++i) { a[i] |= (1LL << 30); }
			for(int i{1}; i < a.size(); ++i) { a[i] |= (1LL << 29); }
		} else {
			for(int i{0}; i < a.size(); ++i) { a[i] |= (1LL << 30); }
		}

		//for(auto& elem : a) std::cout << elem << ' ';
		//std::cout << '\n';

		if (n & 1) {
			std::cout << a[0] << ' ';
			for(int i{0}; i < n >> 1; ++i) std::cout << b[i] << ' ' << a[i+1] << ' ';
		} else {
			for(int i{0}; i < n >> 1; ++i) std::cout << a[i] << ' ' << b[i] << ' ';
		}
		std::cout << '\n';

		//int _1{0}, _2{0};
		//for(auto& elem : a) _1 ^= elem;
		//for(auto& elem : b) _2 ^= elem;
		//std::cout << _1 << ' ' << _2 << '\n';

	}

	return 0;
}

