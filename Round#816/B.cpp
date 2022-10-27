#include <float.h>
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

const int mod = (int) 1e9 + 7;

using namespace std;

// Свойство пропорции a*d == b*c

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while(t--) {
		int n, k, b, s; cin >> n >> k >> b >> s;
		vector<int> a;

		int _sum = s;

		a.push_back(k*b);
		int count = k*b;
		int temp = s - count;
		if(temp >= 0) {
			for(int i{0}; i < n - 1; ++i) {
				if(temp / k > 0) {
					if(temp - k + 1 >= 0) {
						a.push_back(k - 1);
						temp -= k - 1;
						count += k - 1;
					} else {
						a.push_back(temp);
						count += temp;
					}
				} else {
					a.push_back(0);
				}
			}
		}

		/*
		if(s == 38)
			for(auto& elem : a) cout << elem << '\n';
		cout << '\n';
		*/

		if(count == _sum && a.size() == n) {
			for(auto& elem : a) cout << elem << ' ';
			cout << '\n';
		} else if(count + k - 1 >= _sum && a.size() == n) {
			a[0] += _sum - count;
			for(auto& elem : a) cout << elem << ' ';
			cout << '\n';
		} else {
			cout << -1 << '\n';
		}
	}

	return 0;
}
