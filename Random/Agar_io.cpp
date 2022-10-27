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

	int n; cin >> n;
	vector<int> a(n);
	int summ{0};
	for(int i{0}; i < n; ++i) { cin >> a[i]; summ += a[i]; }

	int l{0}; int r{n-1};
	int mid;
	while (l < r) {
		mid = (l+(r-1))/2;
		int number = a[mid];
		for(int i{0}; i < n; ++i) {
			if(number > a[i] && i != mid) {
				number += a[i];
			}
		}

		if(number == summ)
			r = mid;
		else
			l = mid + 1;
	}

	for(int i{0}; i < n; ++i) {
		if(i >= mid) cout << 1 << '\n';
		else cout << 0 << '\n';
	}

	return 0;
}

