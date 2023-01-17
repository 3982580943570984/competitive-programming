#include <cstddef>
#include <functional>
#include <vector>
#include <iostream>
#include <queue>

#define int long long
using namespace std;

const int inf = 3982580943570984;

// vertice, weight
vector<pair<int, int>> adj[1000001];
int dist[1000001];
bool vis[1000001];
vector<int> path(1000001);
// weight, vertice
priority_queue<pair<int, int>> pq;
void djikstra (int s) {
	for (int i = 1; i <= 1000000; ++i) dist[i] = inf;
	dist[s] = 0;
	pq.push({0, s});
	while (!pq.empty()) {
		int a = pq.top().second; pq.pop();
		if (!vis[a]) {
			vis[a] = true;
			for (auto u : adj[a]) {
				int b = u.first;
				int w = u.second;
				if (dist[a] + w < dist[b]) {
					dist[b] = dist[a] + w;
					path[b] = a;
					pq.push({-dist[b], b});
				}
			}
		}
	}
}

void restore_path (int s, int t) {
	vector<int> restore;
	for (int v = t; v != s; v = path[v])
		restore.push_back(v);
	restore.push_back(s);
	reverse(restore.begin(), restore.end());
	for (auto e : restore) cout << e << ' ';
	cout << endl;
}

int32_t main () {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, w; cin >> a >> b >> w;
		adj[a].push_back({b, w});
		adj[b].push_back({a, w});
	}
	djikstra(1);
	if (dist[n] != inf) {
		restore_path(1, n);
	} else {
		cout << -1 << endl;
	}
}
