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

	int n, k, q; cin >> n >> k >> q;
	vector<pair<int, int>> temperatures;
	for(int i{0}; i < n; ++i) {
		int l,r; cin >> l >> r;
		temperatures.push_back(make_pair(l,r));
	}

	for(int i{0}; i < q; ++i) {
		
	}


	return 0;
}

