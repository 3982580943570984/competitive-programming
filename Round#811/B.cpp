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
	while(t--) {
		int n; cin >> n;
		vector<int> a(n);
		for(int i{0}; i < n; ++i) cin >> a[i];
		set<int> aa;
		int temp{0};
		for(int i{n-1}; i >= 0; --i) {
			if(!aa.contains(a[i])) {
				temp = i;
				aa.insert(a[i]);
			}
			else {
				break;
			}
		}

		cout << temp << '\n';
	}

	return 0;
}

