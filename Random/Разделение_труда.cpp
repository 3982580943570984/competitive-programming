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

	vector<int> a(5);
	for(int i{0}; i < 5; ++i) cin >> a[i];

	sort(a.begin(), a.end());

	vector<int> prefix;
	inclusive_scan(a.begin(), a.end(), back_inserter(prefix), plus<>(), 0ll);

	if(!(prefix[4] % 2)) {
		for(int i{0}; i < prefix.size(); ++i) {
			if(prefix[i] == prefix[4] / 2) {
				cout << "YES" << '\n';
				return 0;
			}
		}

		for(int i{0}; i < a.size(); ++i) {
			for(int j{i+1}; j < a.size(); ++j) {
				if(a[i] + a[j] == prefix[4] / 2) {
					cout << "YES" << endl;
					return 0;
				}
			}
		}
	}

	cout << "NO" << '\n';

	return 0;
}
