#include <numeric>
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

#define int long long
using namespace std;

int32_t main () {
	int t; cin >> t;
	while (t--) {
		int m, s; cin >> m >> s;
		set<int> b;
		for (int i = 0; i < m; ++i) {
			int c; cin >> c; b.insert(c);
		}
		for (int i = 1; i <= 1000; ++i) {
			if (!b.contains(i) && s - i >= 0) {
				b.insert(i); s -= i;
			}
		}
		if (s > 0) { cout << "No" << endl; continue; }
		string res = "Yes";
		for (int i = 1; i <= b.size(); ++i) {
			if (!b.contains(i)) {
				res = "No";
				break;
			}
		}
		cout << res << endl;
	}
}
