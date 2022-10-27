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
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	vector<pair<int, int>> oozma(n);
	int index = 0;
	for(auto& monster : oozma) { monster.first = ++index; cin >> monster.second; }

	index = 0;
	vector<pair<int, int>> roar(n);
	for(auto& monster : roar) { monster.first = ++index; cin >> monster.second; }

	sort(all(oozma), [](pair<int, int>& a, pair<int, int>& b){ return a.second < b.second; });
	sort(all(roar), [](pair<int, int>& a, pair<int, int>& b){ return a.second < b.second; });

	for(auto& monster : oozma) cout << monster.first << ' ' << monster.second << '\n';
	cout << '\n';
	for(auto& monster : roar) cout << monster.first << ' ' << monster.second << '\n';
	cout << '\n';

	return 0;
}
