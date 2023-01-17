#include <iostream>
#include <vector>

#define int long long
using namespace std;

int dist[110][110];

int32_t main () {
	int n, d; cin >> n >> d;
	vector<int> a(110); for (int i = 2; i < n; ++i) cin >> a[i];
	vector<int> x(110), y(110);
	for (int i = 1; i <= n; ++i)
		cin >> x[i] >> y[i];

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (i != j)
				dist[i][j] = d * (abs(x[i] - x[j]) + abs(y[i] - y[j])) - a[i];

	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	cout << dist[1][n] << endl;
}
