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

bool solve(int k, int amount) {
	int v{0};
	int breads{amount};
	while(amount > 0) {
		int diff = min(amount, k);
		v += diff;
		amount -= diff;
		amount -= amount / 10;
	}

	return v*2 >= breads;
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	
	int l{1}; int r{n};
	int result{0};
	while(l <= r) {
		int k{(l+r)/2};
		if(solve(k, n)) {
			r = k - 1;
			result = k;
		}
		else
			l = k + 1;
	}

	cout << result << '\n';

	return 0;
}


