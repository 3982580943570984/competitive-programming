#include <iostream>
#include <string>
#include <vector>

#define int long long
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> component;
int cnt = 0;
void dfs (int s, vector<int>& p) {
	if (!vis[s]) {
		vis[s] = true;
		component.push_back(s);
		cnt += p[s];
		for (auto u : adj[s])
			dfs(u, p);
	}
}

int32_t main () {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n, m, k; cin >> n >> m >> k;
	adj = vector<vector<int>>(n*m + 1);
	vis = vector<bool>(n*m + 1);
	vector<int> pictures(n*m + 1);
	vector<string> s(n); for (auto& e: s) cin >> e;
	vector<int> pos;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == '.') {
				pos.push_back(i*m + j);
				if (j > 0) {
					if (s[i][j - 1] == '.') {
						adj[i*m + j].push_back(i*m + j - 1);
						adj[i*m + j - 1].push_back(i*m + j);
					} else pictures[i*m + j]++;
				}
				if (j < m - 1) {
					if (s[i][j + 1] == '.') {
						adj[i*m + j].push_back(i*m + j + 1);
						adj[i*m + j + 1].push_back(i*m + j);
					} else pictures[i*m + j]++;
				}
				if (i > 0) {
					if (s[i - 1][j] == '.') {
						adj[i*m + j].push_back((i - 1)*m + j);
						adj[(i - 1)*m + j].push_back(i*m + j);
					} else pictures[i*m + j]++;
				}
				if (i < n - 1) {
					if (s[i + 1][j] == '.') {
						adj[i*m + j].push_back((i + 1)*m + j);
						adj[(i + 1)*m + j].push_back(i*m + j);
					} else pictures[i*m + j]++;
				}
			}
		}
	}

	vector<int> components(n*m + 1);
	for (auto p : pos) {
		dfs(p, pictures);
		if (!component.empty()) {
			for (auto e : component) components[e] = cnt;
			component.clear(); cnt = 0;
		}
	}
	for (int i = 0; i < k; ++i) {
		int x, y; cin >> x >> y;
		cout << components[(x - 1) * m + y - 1] << '\n';
	}
}
