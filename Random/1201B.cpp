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

	int n; cin >> n;
	int sum{0};
	int half_int{0};
	for(int i{0}; i < n; ++i) {
		int number; cin >> number;
		sum += number;
		half_int = max(half_int, number);
	}

	if(sum % 2 == 0 && half_int <= sum / 2) cout << "YES" << '\n';
	else cout << "NO" << '\n';

	return 0;
}
