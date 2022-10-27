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

	int t; cin >> t;
	for(int i{0}; i < t; ++i) {
		int n, m; cin >> n >> m;
		
		vector<int> gloom(n);
		int sum_gloom{0};
		for(int j{0}; j < n; ++j) {
			int gl; cin >> gl;
			gloom[j] = gl;
			sum_gloom += gl;
		}

		cout << "Sum_gloom" << ' ' << sum_gloom << endl;

		cout << "FRIENDS PAIRS" << endl;

		vector<pair<pair<int,int>, int>> friends(m);
		for(int j{0}; j < m; ++j) {
			int x, y; cin >> x >> y;
			int gl_value = gloom[x-1] + gloom[y-1];
			friends[j] = make_pair(make_pair(x, y), gl_value);
		}

		sort(friends.begin(), friends.end(), [](auto& a, auto& b){ return a.second > b.second; });
		
		int cakes{m - (m % 2)};
		vector<int> invited(n, 0);
		vector<int> gls(m);
		for(int j{0}; j < m; ++j) {
			int gl{0};
			if(invited[friends[j].first.first] == 0) {
				gl += gloom[friends[j].first.first-1];
				invited[friends[j].first.first] = 1;
			}

			if(invited[friends[j].first.second] == 0) {
				gl += gloom[friends[j].first.second-1];
				invited[friends[j].first.second] = 1;
			}

			gls[j] = gl;
		}

		sort(gls.rbegin(), gls.rend());

		int result{0};
		for(int j{0}; j < m; ++j) result += gls[j];

		cout << "Result: \n";
		cout << sum_gloom - result << '\n';
		
		cout << "NEW TEST" << endl;

	}

	return 0;
}

