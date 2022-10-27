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
#define all(x) (x).begin(), x.end()

const int mod = (int) 1e9 + 7;

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<int> a(n);
	for(auto& num : a) cin >> num;

	vector<int> prefix{0};
	inclusive_scan(a.begin(), a.end(), back_inserter(prefix), plus<>(), 0LL);

	int q; cin >> q;
	for(int i{0}; i < q; ++i) {
		int l, r; cin >> l >> r;
		cout << prefix[r] - prefix[l-1] << '\n';
	}
	
	return 0;
}

