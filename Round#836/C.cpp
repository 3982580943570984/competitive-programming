#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define int long long
using namespace std;

int32_t main () {
	int t; cin >> t;
	while (t--) {
		int n, x; cin >> n >> x;

		vector<int> res;
		for (int i = 1; i <= n; ++i) {
			res.push_back(i);
		}
		res[0] = x;
		res[x - 1] = n;
		*(--res.end()) = 1;

		if (!(n & 1)) {
				if (n % x) {
					cout << -1 << endl;
				} else {
					for (auto e : res) cout << e << ' ';
					cout << endl;
				}
		} else {
				if (n % x) {
					cout << -1 << endl;
				} else {
					for (auto e : res) cout << e << ' ';
					cout << endl;
				}
		}
	}
}
