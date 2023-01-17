#include <cstddef>
#include <ios>
#include <iostream>
#include <vector>
#include <map>

#define int long long
using namespace std;

map<int, vector<int>> adj;
bool vis[200001];
vector<int> component;
void dfs (int s) {
	if (!vis[s]) {
		vis[s] = true;
		component.push_back(s);
		for (auto u : adj[s]) {
			dfs(u);
		}
	}
}

int32_t main () {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int t, v, u; cin >> t >> v >> u;
		if (!t) {
			adj[v].push_back(u);
			adj[u].push_back(v);
		}
	}
	vector<vector<int>> components;
	for (int i = 1; i <= n; ++i) {
		dfs(i);
		if (!component.empty()) {
			components.push_back(component);
			component.clear();
		}
	}
	cout << components.size() - 1 << endl;
}
