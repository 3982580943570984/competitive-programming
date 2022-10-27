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
		int x; cin >> x;
		vector<int> keys(3);
		for(int i{0}; i < 3; ++i) { cin >> keys[i]; }

		int count{1};
		--x;
		while(keys[x] != 0) {
			x = keys[x];
			if(x != 0) --x;
			++count;
		}

		if(count == 3) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}

	return 0;
}
