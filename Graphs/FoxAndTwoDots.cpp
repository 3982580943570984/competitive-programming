#include <cstring>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

#define int long long
using namespace std;

vector<int> adj[2501];
bool visited[2501];
vector<int> component;
int edge = 0;
void dfs (int s) {
	if (!visited[s]) {
		visited[s] = true;
		component.push_back(s);
		edge += adj[s].size();
		for (auto& u : adj[s]) {
			dfs(u);
		}
	}
}

int32_t main () {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n, m; cin >> n >> m;
	vector<string> vs(n); for (auto& e : vs) cin >> e;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (j > 0) {
				if (vs[i][j] == vs[i][j-1]) {
					adj[i*m + j].push_back(i*m + j - 1);
					adj[i*m + j - 1].push_back(i*m + j);
				}
			}

			if (j < m - 1) {
				if (vs[i][j] == vs[i][j+1]) {
					adj[i*m + j].push_back(i*m + j + 1);
					adj[i*m + j + 1].push_back(i*m + j);
				}
			}

			if (i > 0) {
				if (vs[i][j] == vs[i-1][j]) {
					adj[i*m + j].push_back((i - 1)*m + j);
					adj[(i - 1)*m + j].push_back(i*m + j);
				}
			}

			if (i < n - 1) {
				if (vs[i][j] == vs[i+1][j]) {
					adj[i*m + j].push_back((i + 1)*m + j);
					adj[(i + 1)*m + j].push_back(i*m + j);
				}
			}
		}
	}
	vector<vector<int>> components;
	vector<int> edges;
	for (int i = 1; i <= n*m; ++i) {
		dfs(i);
		if (!component.empty()) {
			components.push_back(component);
			edges.push_back(edge / 4);
			component.clear();
			edge = 0;
		}
	}

	bool res = false;
	for (int i = 0; i < edges.size(); ++i) {
		if (edges[i] >= components[i].size()) { res = true; break; }
	}
	cout << (res ? "Yes\n" : "No\n");
}
