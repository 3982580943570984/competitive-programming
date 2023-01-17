#include <ios>
#include <iostream>
#include <stdint.h>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>

#define int long long
using namespace std;

vector<int> adj[100005];
bool visited[100005];
bool color[100005];

bool res = true;

void dfs (int s) {
	if (!visited[s]) {
		visited[s] = true;
		for (auto v : adj[s]) {
			dfs(v);
		}
	}
}

void dfs (int s, bool c) {
	if (!visited[s]) {
		visited[s] = true;
		color[s] = c;
		for (auto v : adj[s]) {
			if (!visited[v]) {
				dfs(v, !c);
			} else {
				if (color[s] == color[v]) {
					res = false;
					return;
				}
			}
		}
	}
}

int32_t main () {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 0; i < n; ++i) dfs(i,1);
	cout << endl;
	
	if (res) {
		vector<int> f, s;
		for (int i = 0; i < n; ++i) {
			color[i] ? f.push_back(i+1) : s.push_back(i+1);
		}

		cout << f.size() << '\n';
		for (auto e : f)
			cout << e << ' ';
		cout << '\n';

		cout << s.size() << '\n';
		for (auto e : s)
			cout << e << ' ';
		cout << '\n';
	} else {
		cout << "-1\n";
	}
}
