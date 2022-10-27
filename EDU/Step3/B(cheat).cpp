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
	vector<vector<int>> a(n5, vector<int>(n1*n2*n3*n4));
	for(int i{0}; i < n5; ++i) {
		for(int j{0}; j < n1*n2*n3*n4; ++j) {
			cin >> a[i][j];
		}
	}

	vector<vector<int>> prefMatrixRow(n5, vector<int>());
	for(int i{0}; i < n5; ++i) {
		inclusive_scan(a[i].begin(), a[i].end(), back_inserter(prefMatrixRow[i]), plus<>(), 0LL);
	}

	vector<vector<int>> prefixMatrix(n5+1, vector<int>(n1*n2*n3*n4+1));
	for(int i{1}; i < n5+1; ++i) {
		for(int j{1}; j < n1*n2*n3*n4+1; ++j) {
			prefixMatrix[i][j] = prefMatrixRow[i-1][j-1];
		}
	}

	for(int i{1}; i < n5+1; ++i) {
		for(int j{1}; j < n1*n2*n3*n4+1; ++j) {
			prefixMatrix[i][j] += prefixMatrix[i-1][j];
		}
	}

	for(auto row : prefixMatrix) {
		for(auto elem : row) cout << elem << ' ';
		cout << '\n';
	}

	int q; cin >> q;
	for(int i{0}; i < q; ++i) {
		int l1, l2, l3, l4, l5; cin >> l1 >> l2 >> l3 >> l4 >> l5;
		int r1, r2, r3, r4, r5; cin >> r1 >> r2 >> r3 >> r4 >> r5;
		cout << prefixMatrix[r5][r1*r2*r3*r4] - prefixMatrix[r5][l1*l2*l3*l4-1] - prefixMatrix[l5-1][r1*r2*r3*r4] + prefixMatrix[l5-1][l1*l2*l3*l4-1] << '\n';
	}

	return 0;
}

