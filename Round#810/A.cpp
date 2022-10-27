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

		if(n == 1) {
			cout << 1 << '\n';
			continue;
		}

		vector<int> numbers(n);
		for(int j{0}; j < n; ++j) numbers[j] = j+1;

		for(int j{0}; j < n-1; ++j) {
			if(numbers[j] / (j+1)) swap(numbers[j], numbers[j+1]);
		}

		if(n%2) swap(numbers[n-2], numbers[n-1]);
		
		for(auto number : numbers) cout << number << ' ';
		cout << '\n';
	}

	return 0;
}

