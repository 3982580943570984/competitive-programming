#include <iostream>
#include <vector>
#include <set>

#define int long long
using namespace std;

set<int> adj[300];
bool visited[300];
bool res = true;
void dfs (int s) {
	if (!visited[s]) {
		visited[s] = true;
		for (auto u : adj[s])
			dfs(u);
	}
}

// 1 cycle -> number of egdes == number of nodes
// must be one component

int32_t main () {
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int x, y; cin >> x >> y;
		adj[x].insert(y);
		adj[y].insert(x);
	}
	dfs(1);
	for (int i = 1; i <= n; ++i)
		if (!visited[i])
			res = false;
	cout << (res && m == n ? "FHTAGN!\n" : "NO\n");
}
