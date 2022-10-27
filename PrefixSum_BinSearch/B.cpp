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

	int n,m; cin >> n >> m;
	vector<int> a(n);
	for(int i{0}; i < n; ++i) { cin >> a[i]; }
	sort(a.begin(), a.end());

	for(int i{0}; i < m; ++i) {
		int number; cin >> number;
		cout << (upper_bound(a.begin(), a.end(), number) - a.begin()) << ' ';
	}

	return 0;
}
