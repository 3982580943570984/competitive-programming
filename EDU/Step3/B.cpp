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

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n1, n2, n3, n4, n5; cin >> n1 >> n2 >> n3 >> n4 >> n5;
	vector<vector<vector<vector<vector<int>>>>> a(n5, vector<vector<vector<vector<int>>>> (n4, vector<vector<vector<int>>> (n3, vector<vector<int>> (n2, vector<int> (n1)))));
	for(auto& _5d : a) {
		for(auto& _4d : _5d) {
			for(auto& _3d : _4d) {
				for(auto& _2d : _3d) {
					for(auto& _1d : _2d) {
						cin >> _1d;
					}
				}
			}
		}
	}

	vector<vector<vector<vector<vector<int>>>>> pref(n5+1, vector<vector<vector<vector<int>>>> (n4+1, vector<vector<vector<int>>> (n3+1, vector<vector<int>> (n2+1, vector<int> (n1+1)))));
	for(int i{0}; i < n5; ++i) {
		for(int j{0}; j < n4; ++j) {
			for(int k{0}; k < n3; ++k) {
				for(int l{0}; l < n2; ++l) {
					for(int m{0}; m < n1; ++m) {
						pref[i+1][j+1][k+1][l+1][m+1]
							= pref[i][j+1][k+1][l+1][m+1] + pref[i+1][j][k+1][l+1][m+1] + pref[i+1][j+1][k][l+1][m+1] + pref[i+1][j+1][k+1][l][m+1] + pref[i+1][j+1][k+1][l+1][m]
							
							- pref[i+1][j+1][k+1][l][m] - pref[i][j+1][k+1][l+1][m] - pref[i][j][k+1][l+1][m+1] - pref[i+1][j][k][l+1][m+1] - pref[i+1][j+1][k][l][m+1]
							- pref[i][j+1][k][l+1][m+1] - pref[i][j+1][k+1][l][m+1] - pref[i+1][j][k+1][l][m+1] - pref[i+1][j][k+1][l+1][m] - pref[i+1][j+1][k][l+1][m]

							+ pref[i+1][j+1][k][l][m] + pref[i][j+1][k+1][l][m] + pref[i][j][k+1][l+1][m] + pref[i][j][k][l+1][m+1] + pref[i+1][j][k][l][m+1]
							+ pref[i+1][j][k+1][l][m] + pref[i+1][j][k][l+1][m] + pref[i][j+1][k][l+1][m] + pref[i][j+1][k][l][m+1] + pref[i][j][k+1][l][m+1]

							- pref[i+1][j][k][l][m] - pref[i][j+1][k][l][m] - pref[i][j][k+1][l][m] - pref[i][j][k][l+1][m] - pref[i][j][k][l][m+1]
							+ pref[i][j][k][l][m] + a[i][j][k][l][m];
					}
				}
			}
		}
	}

	int q; cin >> q;
	for(int i{0}; i < q; ++i) {
		int l1, l2, l3, l4, l5; cin >> l1 >> l2 >> l3 >> l4 >> l5;
		int r1, r2, r3, r4, r5; cin >> r1 >> r2 >> r3 >> r4 >> r5;
		l1--, l2--, l3--, l4--, l5--;
		cout << pref[r5][r4][r3][r2][r1]
			- pref[l5][r4][r3][r2][r1] - pref[r5][l4][r3][r2][r1] - pref[r5][r4][l3][r2][r1] - pref[r5][r4][r3][l2][r1] - pref[r5][r4][r3][r2][l1]

			+ pref[l5][l4][r3][r2][r1] + pref[r5][l4][l3][r2][r1] + pref[r5][r4][l3][l2][r1] + pref[r5][r4][r3][l2][l1] + pref[l5][r4][r3][r2][l1]
			+ pref[l5][r4][l3][r2][r1] + pref[l5][r4][r3][l2][r1] + pref[r5][l4][r3][l2][r1] + pref[r5][l4][r3][r2][l1] + pref[r5][r4][l3][r2][l1]

			- pref[l5][l4][l3][r2][r1] - pref[r5][l4][l3][l2][r1] - pref[r5][r4][l3][l2][l1] - pref[l5][r4][r3][l2][l1] - pref[l5][l4][r3][r2][l1]
			- pref[r5][l4][r3][l2][l1] - pref[r5][l4][l3][r2][l1] - pref[l5][r4][l3][r2][l1] - pref[l5][r4][l3][l2][r1] - pref[l5][l4][r3][l2][r1]
			
			+ pref[l5][l4][l3][l2][r1] + pref[r5][l4][l3][l2][l1] + pref[l5][r4][l3][l2][l1] + pref[l5][l4][r3][l2][l1] + pref[l5][l4][l3][r2][l1]
			- pref[l5][l4][l3][l2][l1]
			<< '\n';
	}

	return 0;
}

