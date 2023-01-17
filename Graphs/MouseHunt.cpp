#include <iostream>
#include <cstring>
#include <vector>
#include <map>

#define int long long
using namespace std;

map<int, vector<int>> adj;
vector<bool> vis;
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

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n; cin >> n;
	vector<int> c(n); for (auto& e : c) cin >> e;
	vector<int> a(n); for (auto& e : a) cin >> e;
	vis.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		adj[i].push_back(a[i-1]);
	}

	vector<vector<int>> components;
	for (int i = 1; i <= n; ++i) {
		dfs(i);
		if (!component.empty()) {
			if (component.size() <= 2) components.push_back(component);
			component.clear();
			vis = vector<bool>(n + 1);
		}
	}
	int res = 0;
	vector<bool> proc(n + 1);
	for (auto component : components) {
		int m = 300000;
		for (auto v : component) {
			cout << v << ' ';
			if (!proc[v]) {
				proc[v] = true;
				m = min(c[v-1], m);
			}
		} cout << endl;
		if (m != 300000) { /*cout << m << ' ';*/ res += m; }
	}
	cout << res << endl;
}
