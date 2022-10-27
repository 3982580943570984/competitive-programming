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

	int n, m; cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for(int i{0}; i < n; ++i) {
		for(int j{0}; j < m; ++j) {
			cin >> a[i][j];
		}
	}

	vector<vector<int>> prefMatrixRow(n, vector<int>());
	for(int i{0}; i < n; ++i) {
		inclusive_scan(a[i].begin(), a[i].end(), back_inserter(prefMatrixRow[i]), plus<>(), 0LL);
	}

	vector<vector<int>> prefixMatrix(n+1, vector<int>(m+1));
	for(int i{1}; i < n+1; ++i) {
		for(int j{1}; j < m+1; ++j) {
			prefixMatrix[i][j] = prefMatrixRow[i-1][j-1];
		}
	}

	for(int i{1}; i < n+1; ++i) {
		for(int j{1}; j < m+1; ++j) {
			prefixMatrix[i][j] += prefixMatrix[i-1][j];
		}
	}

	int q; cin >> q;
	for(int i{0}; i < q; ++i) {
		int lx, ly, rx, ry; cin >> lx >> ly >> rx >> ry;
		cout << prefixMatrix[rx][ry] - prefixMatrix[rx][ly-1] - prefixMatrix[lx-1][ry] + prefixMatrix[lx-1][ly-1] << '\n';
	}

	return 0;
}

