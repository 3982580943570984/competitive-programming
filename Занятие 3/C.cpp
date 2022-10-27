#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include <cmath>

#define int long long int

using namespace std;

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	for (int i{0}; i < t; i++) {
		int a; cin >> a;
		int b; cin >> b;
		int c; cin >> c;
		int r; cin >> r;

		int minutes = max(a,b) - min(a,b) + 1;
		int left = c - r;
		int right = c + r;
		cout << max(a,b) - right + left - min(a,b) << endl;
	}

	return 0;
}
