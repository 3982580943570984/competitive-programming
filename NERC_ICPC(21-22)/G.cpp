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

const int MOD = (int) 1e9 + 7;

using namespace std;

int getEmotesNumber(int index, int k) {
	if(index > k)
		return k*k - (2*k - 1 - index)*(2*k - index) / 2;
	else
		return ((1 + index) * index) / 2;
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int k, x; cin >> k >> x;

		int left{0}, right{2*k - 1};
		while (right - left > 1) {
			int mid = (left + right) / 2;
			if(getEmotesNumber(mid, k) >= x) {
				right = mid;
			} else {
				left = mid;
			}
		}
		cout << right << '\n';
	}

	return 0;
}

