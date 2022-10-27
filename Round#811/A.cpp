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
		int n, H, M; cin >> n >> H >> M;
		int minutes = H*60 + M;
		vector<int> time(n);
		for(int i{0}; i < n; ++i) {
			int h, m; cin >> h >> m;
			if(h*60 + m < minutes)
				time[i] = 1440 - minutes + h*60 + m;
			else
				time[i] = h*60 + m - minutes;
		}
		auto _min = min_element(time.begin(), time.end());
		cout << *_min / 60 << ' ' << *_min % 60 << '\n';
	}

	return 0;
}

