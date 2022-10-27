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

	string s; cin >> s;
	int h = s.size();
	vector<int> diff(h);
	for(int i{0}; i < s.size(); ++i) { char c = s[i] - 'a'; h += (int) c; diff[i] = c; }
	cout << h << '\n';

	auto mi = min_element(diff.begin(), diff.end());
	auto ma = max_element(diff.begin(), diff.end());

	if(*ma - *mi > 0) {
		swap(*ma, *mi);
		for(auto c : diff) {
			cout << static_cast<char> (c + 'a');
		}
	}

	return 0;
}

