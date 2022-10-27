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

bool check(int workers, vector<int> trash) {
	bool flag = true;

	for(int i{0}; i < trash.size(); ++i) {
		if(trash[i] > workers * 2) {
			flag = false;
			break;
		}

		if(i + 1 < trash.size()) {
			if(trash[i] - (workers*2 - trash[i]) >= 0)
				trash[i+1] += trash[i] - (workers * 2 - trash[i]);
		} else {
			trash[i] - workers <= 0 ? flag = true : flag = false;
		}
	}

	return flag;
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<int> trash(n);
	for(int i{0}; i < n; ++i) cin >> trash[i];

	int left{0}, right{200000};
	while(left <= right) {
		int mid = (left + right) / 2;
		if(check(mid, trash))
			right = mid - 1;
		else
			left = mid + 1;
	}

	cout << right + 1 << '\n';

	return 0;
}

