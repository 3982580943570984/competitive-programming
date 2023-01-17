#include <iostream>
#include <map>
#include <vector>

#define int long long
using namespace std;

map<int, vector<int>> adj;
vector<bool> vis;
vector<int> a;
int leaf = 0;
int temp;
void dfs (int s, int m) {
	if (!vis[s]) {
		vis[s] = true;
		if (adj[s].size() == 1 && a[s] == 1 && s != 1) --m;
		if (m < 0) return;
		if (adj[s].size() == 1 && s != 1) ++leaf;
		for (auto u : adj[s]) {
			if (a[s] == 1)
				dfs(u, m - 1);
			else
				dfs(u, temp);
		}
	}
}

int32_t main () {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n, m; cin >> n >> m; temp = m;
	vis.resize(n + 1); a.resize(n + 1);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 0; i < n-1; ++i) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1, m);
	cout << leaf << endl;
}
