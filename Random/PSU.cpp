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
	string s; cin >> s;
	
	int result{0};
	for(size_t i{0}; i < n-1; ++i) {
		if(s.substr(i, 3) == "PSU") ++result;
	}

	cout << result << '\n';

	int q{0}; cin >> q;
	for(int i{0}; i < q; ++i) {
		int index; cin >> index; --index;

		int temp1{0};
		int temp2{0};

		if(index <= n-2 && s.substr(index, 3) == "PSU") ++temp1;
		if(index >= 1 && index <= n-1 && s.substr(index-1, 3) == "PSU") ++temp1;
		if(index >= 2 && s.substr(index-2, 3) == "PSU") ++temp1;
		cin >> s[index];

		if(index <= n-2 && s.substr(index, 3) == "PSU") ++temp2;
		if(index >= 1 && index <= n-1 && s.substr(index-1, 3) == "PSU") ++temp2;
		if(index >= 2 && s.substr(index-2, 3) == "PSU") ++temp2;

		result -= temp1 - temp2;
		cout << result << '\n';
	}

	return 0;
}
