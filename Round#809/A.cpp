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
	for(int i{0}; i < t; i++) {
		int n, m; cin >> n >> m;
		vector<pair<int, int>> places;
		string result(m, 'B');
		for(int j{0}; j < n; j++) {
			int place; cin >> place;
			int mmin = min(place - 1, m - place);
			int maxx = max(place - 1, m - place);
			if(result[mmin] != 'A') result[mmin] = 'A';
			else result[maxx] = 'A';
		}
		cout << result << '\n';
	}

	return 0;
}
