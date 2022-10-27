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

	int n, m; cin >> n >> m;
	vector<int> a(n);
	vector<int> forward(n);
	vector<int> backward(n);
	int height_prev(0);
	for(int i{0}; i < n; ++i) {
		cin >> a[i];
	}

	for(int i{1}; i < n; ++i) {
		if(a[i] > a[i-1]) forward[i] = forward[i-1];
		else forward[i] = forward[i-1] + a[i-1] - a[i];
	}

	for(int i{n-1}; i > 0; --i) {
		if(a[i] > a[i-1]) backward[n-i] = backward[n-i-1] + a[i] - a[i-1];
		else backward[n-i] = backward[n-i-1];
	}

	for(int i{0}; i < m; ++i) {
		int s, t; cin >> s >> t;
		--s, --t;
		if(s < t) {
			cout << forward[t] - forward[s] << '\n';
		} else {
			cout << backward[n-t-1] - backward[n-s-1] << '\n';
		}
	}

	return 0;
}

