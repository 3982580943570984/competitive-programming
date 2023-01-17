#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define int long long
using namespace std;

int32_t main () {
	int x1, y1, r1, b1; cin >> x1 >> y1 >> r1 >> b1;
	int x2, y2, r2, b2; cin >> x2 >> y2 >> r2 >> b2;
	int dist = pow(x2 - x1, 2) + pow(y2 - y1, 2);
	cout << dist << ' ' << pow(r1 - r2, 2) << endl;
	cout << (r1 > r2) << endl;
	if (dist == 0 && r1 == r2) {
		cout << max({0ll, b1 + b2}) << endl;
		return 0;
	}
	if (dist >= pow(r2 - r1, 2) && r2 > r1) {
		cout << max({0ll, b2, b1 + b2}) << endl;
		return 0;
	}
	if (dist >= pow(r1 - r2, 2) && r1 > r2) {
		cout << max({0ll, b1, b1 + b2}) << endl;
		return 0;
	}
	if (dist <= pow(r1 + r2, 2)) {
		cout << max({0ll, b1, b2, b1 + b2}) << endl;
		return 0;
	}
	if (dist > pow(r1 + r2, 2)) {
		cout << max({0ll, b1, b2}) << endl;
		return 0;
	}
}
