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
		int n, x; cin >> n >> x;
		vector<int> a(n);
		cin >> a[0];
		int _min = min(abs(a[0] - x), abs(a[0] + x));
		int _max = max(abs(a[0] - x), abs(a[0] + x));
		int count{0};
		for(int i{1}; i < n; ++i) {
			cin >> a[i];

			int curr_min = min(abs(a[i] - x), abs(a[i] + x));
			int curr_max = max(abs(a[i] - x), abs(a[i] + x));

			if(_max >= curr_min && _max <= curr_max ||
			   _min >= curr_min && _min <= curr_max ||
			   _max >= curr_max && _min <= curr_min ||
			   _max <= curr_max && _min >= curr_min) {
				if(_min <= curr_min) _min = curr_min;
				if(_max >= curr_max) _max = curr_max;
				continue;
			} else {
				++count;
				_min = curr_min;
				_max = curr_max;
			}
		}

		cout << count << '\n';
	}

	return 0;
}

