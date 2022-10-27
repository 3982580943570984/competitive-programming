#include <iostream>

using namespace std;

#define int long long int

int32_t main () {

	int k, n; cin >> k >> n;
	cout << min(n % k, k - n % k) << '\n';
	return 0;
}
