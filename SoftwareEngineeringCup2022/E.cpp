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
	vector<int> l;
	vector<int> r;
	int current{0};
	for(int i{0}; i < n; ++i) {
		int left, right; cin >> left >> right;
		l.push_back(left);
		r.push_back(right);
	}

	for(int i{n-1}; i >= 0; --i) {
		if(!current) {
			if(r[i] < l[i]) {
				cout << 'R';
				current = 1;
			}
		} else {
			if(l[i] < r[i]) {
				cout << 'L';
				current = 0;
			}
		}
		cout << 'S';
	}
	
	return 0;
}

