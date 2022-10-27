#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include <cmath>

#define int long long int

// greatest common divisor
int gcd (int a, int b) { return b ? gcd (b, a % b) : a; }

using namespace std;

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, x, y;
	cin >> a >> b >> x >> y;

	int ratio = gcd(x, y);

	x /= ratio;
	y /= ratio;

	cout << min(a/x, b/y) << endl;

	return 0;
}

