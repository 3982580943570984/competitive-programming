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

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int a, b, x; cin >> a >> b >> x;
		if(a < x && b < x) {
			cout << "NO" << '\n';
			continue;
		}

		string result = "NO";
		while(a != 0 && b != 0) {
			if(a < b)
				swap(a, b);

			if ((a - x) % b == 0 && a >= x) {
				result = "YES";
				break;
			} else {
				a %= b;
			}
		}

		cout << result << '\n';
	}

	return 0;
}


