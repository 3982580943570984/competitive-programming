#include <ios>
#include <iostream>
#include <stdint.h>
#include <vector>
#include <set>
#include <algorithm>

#define int long long
using namespace std;

set<int> adj[200000];
bool visited[200000];
vector<int> component;
vector<int> c;
void dfs (int s) {
	if (!visited[s]) {
		component.push_back(c[s-1]);
		visited[s] = true;
		for (auto v : adj[s]) {
			dfs(v);
		}
	}
}

int32_t main () {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, m; cin >> n >> m;
	c.resize(n); for (auto& e : c) cin >> e;
	for (int i = 0; i < m; ++i) {
		int x, y; cin >> x >> y;
		adj[x].insert(y);
		adj[y].insert(x);
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		dfs(i);
		if (!component.empty())
			res += *min_element(component.begin(), component.end());
		component.clear();
	}
	cout << res << endl;
}
