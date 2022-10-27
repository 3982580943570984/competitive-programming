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

using namespace std;

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int _3 = n / 3;
		int _2 = n / 2;
		int steps2{_2};
		int steps3{_3};
		if((n - 4) % 3 == 0) {
			int temp = n / 3 + 2;
			if(n / 3 > 0)
				temp = (n / 3 - 1) + 2;
			cout << temp << '\n';
			continue;
		}
		if(n == 1) {
			steps2 = 2;
			steps3 = 2;
			cout << 2 << '\n';
			continue;
		}
		if(n - _2 * 2 == 1) {
			steps2 = _2 + 2;
		}
		if(n - (_2 - 1)* 2 == 3) {
			steps2 = _2;
		}
		if(n - _3 * 3 == 1) {
			steps3 = _3 + 2;
		}
		if(n - _3 * 3 == 2) {
			steps3 = _3 + 1;
		}
		cout << min(steps2, steps3) << '\n';
	}

	return 0;
}
