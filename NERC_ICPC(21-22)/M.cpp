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

	int t; cin >> t;
	while(t--) {
		int x, y; cin >> x >> y;
		int half = (x + y) / 2;
		int res_x{-1}, res_y{-1};
		for(int i{0}; i <= 50; ++i) {
			for(int j{0}; j <= 50; ++j) {
				if(i + j == half && (abs(x - i) + abs(y - j)) == half) {
					res_x = i;
					res_y = j;
					break;
				}
			}
		}

		cout << res_x << ' ' << res_y << '\n';
	}

	return 0;
}

