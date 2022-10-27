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
		int a,b,c; cin >> a >> b >> c;
		cout << a + b + c << ' ' << b + c << ' ' << c << '\n';
	}

	return 0;
}

