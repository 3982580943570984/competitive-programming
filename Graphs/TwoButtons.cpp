#include <iostream>
#include <stdint.h>
#include <queue>

#define int long long
using namespace std;

vector<int> adj[40000];
bool visited[40000];
queue<int> q;

int n, m;
int _distance[40000];

void bfs (int x) {
	visited[x] = true;
	_distance[x] = 0;
	q.push(x);
	while (!q.empty()) {
		int s = q.front(); q.pop();
		for (auto u : adj[s]) {
			if (visited[u]) continue;
			visited[u] = true;
			_distance[u] = _distance[s] + 1;
			q.push(u);
		}
	}
}

int32_t main () {
	cin >> n >> m;
	for (int i = 0; i < 40000; ++i) {
		if (i - 1 > 0) {
			adj[i].push_back(i - 1);
		}
		if ((i << 1) < 40000) {
			adj[i].push_back(i << 1);
		}
	}
	bfs(n);
	cout << _distance[m] << endl;
}
