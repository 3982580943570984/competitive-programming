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
#define inf 1000000007

using namespace std;

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while(t--) {
		int n, a, b; cin >> n >> a >> b;
		vector<int> numbers(n);
		numbers[0] = a;
		numbers[n - 1] = b;

		int j{1};
		for(int i{n}; i > 0; --i) {
			if(i != a && i != b) numbers[j++] = i;
		}

		if(*min_element(numbers.begin(), numbers.begin() + (n/2)) == a && *max_element(numbers.begin() + n/2, numbers.end()) == b) {
			for(auto num : numbers) cout << num << ' ';
			cout << '\n';
		} else {
			cout << -1 << '\n';
		}
	}

	return 0;
}

