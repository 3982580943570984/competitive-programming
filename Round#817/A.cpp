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
		string name; cin >> name;
		string result("NO");
		if(n == 5) {
			if (name.find('T') != string::npos
					&& name.find('i') != string::npos
					&& name.find('m') != string::npos
					&& name.find('u') != string::npos
					&& name.find('r') != string::npos)
				result = "YES";
		}
		cout << result << '\n';
	}

	return 0;
}

