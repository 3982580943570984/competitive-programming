#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define int long long
using namespace std;

int32_t main () {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		if (n & 1) {
			for (int i = 0; i < n; ++i) {
				cout << n << ' ';
			} cout << endl;
		} else {
			cout << 3 << ' ' << 1 << ' ';
			for (int i = 0; i < n - 2; ++i) {
				cout << 2 << ' ';
			} cout << endl;
		}
	}
}
