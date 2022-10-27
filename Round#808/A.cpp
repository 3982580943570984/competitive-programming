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
		string result("YES");
		for(int i{1}; i < n; ++i) {
			if(a[i] % a[0]) {
				result = "NO";
				break;
			}
		}
		cout << result << '\n';
	}

	return 0;
}

