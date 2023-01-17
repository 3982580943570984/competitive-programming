#include <algorithm>
#include <iostream>
#include <stdint.h>

#define int long long
using namespace std;

int32_t main () {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n; cin >> n;

	int dist[n][n];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> dist[i][j];

	int q; cin >> q;
	for (int m = 0; m < q; ++m) {
		int a, b, c; cin >> a >> b >> c; --a; --b;
		if (dist[a][b] > c) {
			dist[a][b] = c;
			dist[b][a] = c;
				for (int i = 0; i < n; ++i)
					for (int j = 0; j < n; ++j)
						dist[i][j] = min({
								dist[i][j],
								dist[i][a] + c + dist[b][j],
								dist[i][b] + c + dist[a][j]
						});
		}

		int res = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				res += dist[i][j];
		
		cout << res / 2 << '\n';
	}
}
