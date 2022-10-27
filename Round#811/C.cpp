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
		int s; cin >> s;
		vector<int> numbers;
		for(int i{9}; i > 0; --i) {
			if(s-i >= 0) {
				numbers.push_back(i);
				s -= i;
			}
		}
		
		reverse(numbers.begin(), numbers.end());
		for(auto number : numbers)
			cout << number;
		cout << '\n';
	}
	
	return 0;
}

