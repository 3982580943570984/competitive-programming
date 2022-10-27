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
		int n, m; cin >> n >> m;
		string a; cin >> a;
		string b; cin >> b;

		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		string result = "NO";
		if(a.substr(0, m-1) == b.substr(0, m-1)) {
			for(int i{m-1}; i < n; ++i)
				if(a[i] == b[m-1]) {
					result = "YES";
					break;
				}
		}
		
		cout << result << '\n';
	}

	return 0;
}

