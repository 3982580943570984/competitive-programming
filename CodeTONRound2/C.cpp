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
		vector<int> a(m);
		int _min{100000};
		int _max{0};
		for(int i{0}; i < m; ++i) {
			cin >> a[i];
			if(a[i] > _max) _max = a[i];
			if(a[i] < _min) _min = a[i];
		}
		stable_sort(a.begin(), a.end());

		vector<int> _ranges(m);
		_ranges[0] = (n-_max + _min - 1);
		for(int i{1}; i < m; ++i) {
			_ranges[i] = a[i] - a[i-1] - 1;
		}

		stable_sort(_ranges.rbegin(), _ranges.rend());
		int result{n};
		int decrease{2};
		for(int i{0}; i < m; ++i) {
			if(_ranges[i] - decrease >= 0) 
				if(i == 0)
					result -= _ranges[i] - 1;
				else
					result -= _ranges[i] - decrease;

			decrease += 2;
		}
	
		cout << result << '\n';

	}

	return 0;
}

