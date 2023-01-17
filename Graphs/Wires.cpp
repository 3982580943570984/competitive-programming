#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

//#define int long long
using namespace std;

// v u w
vector<int> component;
void dfs (int s, map<int, vector<pair<int, int>>>& adj, map<int, bool>& vis) {
	if (!vis[s] && !adj[s].empty()) {
		vis[s] = true;
		component.push_back(s);
		for (auto [u, w] : adj[s]) {
			dfs(u, adj, vis);
		}
	}
}

int32_t main () {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> v;
		map<int, vector<pair<int, int>>> adj; map<int, bool> vis;
		for (int i = 1; i <= n; ++i) {
			int x, y; cin >> x >>y;
			v.push_back(x); v.push_back(y);
			adj[x].push_back({y, i});
			adj[y].push_back({x, i});
		}
		if (n == 1) {
			cout << 0 << endl; continue;
		}
		vector<vector<int>> components;
		for (auto e : v) {
			dfs(e, adj, vis);
			if (!component.empty()) {
				components.push_back(component);
				component.clear();
			}
		}
		cout << components.size() - 1 << endl;
		for (int i = 0; i < components.size() - 1; ++i) {
			auto f = components[i].back();
			auto s = components[i + 1].front();
			cout << adj[f].front().second << ' ' << f << ' ' << s << endl;
		}
	}
}
