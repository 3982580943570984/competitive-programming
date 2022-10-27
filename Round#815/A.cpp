#include <float.h>
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

// Свойство пропорции a*d == b*c

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		int x = a*d, y = b*c;
		if(x == y)
			cout << 0 << '\n';
		else {
			if(x > y) swap(x, y);
			if(x == 0 || y%x == 0)
				cout << 1 << '\n';
			else
				cout << 2 << '\n';
		}
	}

	return 0;
}

