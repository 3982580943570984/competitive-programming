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

	int t; cin >> t;
	while (t--) {
		int n, k, x, y; cin >> n >> k >> x >> y;
		
		// a - x, b - y;
		vector<pair<string, int>> a_athletes;
		vector<pair<string, int>> b_athletes;
		for (int i{0}; i < n; ++i) {
			string sport; cin >> sport;
			int skill; cin >> skill;

			if(sport == "A") a_athletes.push_back(make_pair(sport, skill));
			if(sport == "B") b_athletes.push_back(make_pair(sport, skill));
		}


		
	}

	return 0;
}

