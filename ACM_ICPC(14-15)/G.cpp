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
#define inf 1000000007

using namespace std;

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, a, b; cin >> n >> a >> b;
	vector<vector<int>> variants(n + 1, vector<int>{0, 0});
	variants[0][0] = 1;
	variants[0][1] = 1;
	for(int i{0}; i < n; ++i) {
		for(int j{1}; j <= a; ++j) {
			if(i + j > n) break;
			variants[i+j][0] = (variants[i+j][0] + variants[i][1]) % inf;
		}
		for(int j{1}; j <= b; ++j) {
			if(i + j > n) break;
			variants[i+j][1] = (variants[i+j][1] + variants[i][0]) % inf;
		}
	}

	cout << (variants.back()[0] + variants.back()[1]) % inf << '\n';

	return 0;
}

