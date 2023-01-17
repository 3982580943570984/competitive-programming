#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <map>

//#define int long long
using namespace std;

map<int, vector<int>> adj;
queue<int> q;
vector<int> dist(32769, 100000);
void bfs (int x) {
	dist[x] = 0;
	adj[x].push_back((x + 1) % 32768);
	adj[x].push_back((x * 2) % 32768);
	q.push(x);
	while(!q.empty()) {
		int s = q.front(); q.pop();
		for (auto v : adj[s]) {
			if (dist[v] > dist[s] + 1) {
				dist[v] = dist[s] + 1;
				adj[v].push_back((v + 1) % 32768);
				adj[v].push_back((v * 2) % 32768);
				q.push(v);
			}
		}
	}
}

int32_t main () {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n; cin >> n;
	vector<int> a(n); for (auto& e : a) cin >> e;
	for (auto e : a) {
		bfs(e);
		cout << dist[0] << endl;
		dist = vector<int>(32769, 100000);
	}
}
