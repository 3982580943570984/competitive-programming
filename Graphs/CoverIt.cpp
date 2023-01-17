#include <algorithm>
#include <cstddef>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstring>

#define int long long
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;
void dfs (int s, int d, vector<int>& odd, vector<int>& even) {
	if (!vis[s]) {
		vis[s] = true;
		d % 2 ? odd.push_back(s) : even.push_back(s);
		for (auto u : adj[s])
			dfs(u, d + 1, odd, even);
	}
}

int32_t main () {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		adj = vector<vector<int>>(n + 1);
		vis = vector<bool>(n + 1);
		for (int i = 0; i < m; ++i) {
			int v, u; cin >> v >> u;
			adj[v].push_back(u);
			adj[u].push_back(v);
		}

		vector<int> odd, even;
		dfs(1, 1, odd, even);

		if (odd.size() < even.size()) {
			cout << odd.size() << endl;
			for (auto e : odd)
				cout << e << ' ';
			cout << endl;
		} else {
			cout << even.size() << endl;
			for (auto e : even)
				cout << e << ' ';
			cout << endl;
		}
	}
}
