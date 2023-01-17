#include <iostream>
#include <stdint.h>
#include <vector>

#define int long long
using namespace std;

int32_t main () {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n); for (auto& e : a) cin >> e;
		int l = 0, r = 0;
		for (int i = 0; i < n; ++i)
			a[i] ? ++l : ++r;

		if (l <= n/2) {
			cout << r << endl;
			for (int i = 0; i < r; ++i) cout << "0 ";
			cout << endl;
		} else {
			if (l & 1) {
				cout << l - 1 << endl;
				for (int i = 0; i < l - 1; ++i) cout << "1 ";
			} else {
				cout << l << endl;
				for (int i = 0; i < l; ++i) cout << "1 ";
			}
			cout << endl;
		}
	}
}
