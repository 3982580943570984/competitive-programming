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
	for(int i{0}; i < t; ++i) {
		int n; cin >> n;
		vector<int> dividers(n);
		for(int j{0}; j < n; ++j) cin >> dividers[j];
		sort(dividers.begin(), dividers.end());

		int x = dividers[0] * dividers[n-1];

		vector<int> true_dividers;
		for(int j{2}; j*j <= x; ++j) {
			if(x % j == 0) {
				true_dividers.push_back(j);
				if(x/j != j) true_dividers.push_back(x/j);
			}
		}

		sort(true_dividers.begin(), true_dividers.end());

		(dividers == true_dividers) ? cout << x << '\n' : cout << -1 << '\n';
	}

	return 0;
}

