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

int32_t main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);

	int t; std::cin >> t;
	while (t--) {

		int n; std::cin >> n;
		std::string line; std::cin >> line;
		
		int last_value{0};
		for(int i{0}; i < n; ++i) { if(line[i] == 'L') last_value += i; else last_value += n - i - 1; }
		
		int k{0}, index_left{0}, index_right{n-1};
		while(index_left <= (n >> 1) || index_right > (n >> 1)) {
			if (index_left < (n >> 1) && line[index_left] == 'L') {
				++k; last_value += n - index_left - 1 - index_left; std::cout << last_value << ' ';
			}
			if (index_right >= (n >> 1) && line[index_right] == 'R') {
				++k; last_value += index_right - (n - index_right - 1); std::cout << last_value << ' ';
			}
			++index_left; --index_right;
		}

		while(k++ < n) std::cout << last_value << ' ';
		std::cout << '\n';
	}

	return 0;
}

