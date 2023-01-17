#include <iostream>

#define int long long
using namespace std;

const int inf = 20000;

int32_t main () {
	int n, m; cin >> n >> m;
	int adj[20][20];
	for (int i = 0; i < 20; ++i)
		for (int j = 0; j < 20; ++j)
			adj[i][j] = inf;

	for (int i = 1; i <= m; ++i) {
		int x, y, w; cin >> x >> y >> w;
		adj[x][y] = min(adj[x][y], w);
		adj[y][x] = min(adj[y][x], w);
	}

	int dist[20][20];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (i != j)
				dist[i][j] = adj[i][j];

	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			cout << dist[i][j] << ' ';
		cout << endl;
	}

	cout << dist[1][n] + dist[1][1] << endl;
}
