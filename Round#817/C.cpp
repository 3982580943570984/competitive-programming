#include <cstdint>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <limits.h>
#include <limits>
#include <numeric>
#include <stdint.h>
#include <type_traits>
#include <utility>
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
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> result(3);
		map<string, vector<int>> players;
		for(int i{0}; i < n; ++i) {
			string word; cin >> word;
			players[word].push_back(0);
		}
		for(int i{0}; i < n; ++i) {
			string word; cin >> word;
			players[word].push_back(1);
		}
		for(int i{0}; i < n; ++i) {
			string word; cin >> word;
			players[word].push_back(2);
		}

		for(auto& elem : players) {
			if(elem.second.size() == 1) result[*elem.second.begin()] += 3;
			if(elem.second.size() == 2) { result[*elem.second.begin()] += 1; result[*(elem.second.end() - 1)] += 1; }
		}

		for(auto& elem : result) cout << elem << ' ';
		cout << '\n';

	}

	return 0;
}

