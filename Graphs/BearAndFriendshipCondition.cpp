#include <cstddef>
#include <ios>
#include <iostream>
#include <cinttypes>
#include <stdint.h>
#include <vector>

#define int long long
using namespace std;

vector<int> adj[1];
bool visited[1];

vector<int> component;

void dfs (int s) {
	if (!visited[s]) {
		visited[s] = true;
		component.push_back(s);
		for (auto v : adj[s]) {
			dfs(v);
		}
	}
}

// DSU Implementation
vector<int> edges[150001];	// adjacency list
int label[150001];			// curr component for each vertice
int sz[150001];				// size of each component
int numberOfEdges[150001];	// number of edges in each component

void init () {
	for (int i = 0; i < 150001; ++i) {
		label[i] = i;
		sz[i] = 1;
	}
}

void relabel (int v, int t) {
	if (label[v] == t) return;
	label[v] = t;
	for (auto x : edges[v])
		relabel(x, t);
}

void merge (int u, int v) {
	edges[u].push_back(v);
	edges[v].push_back(u);
	int cu = label[u], cv = label[v]; // component number for u & v
	if (cu == cv) {
		++numberOfEdges[cu];
		return;
	}
	if (sz[cu] > sz[cv]) {
		numberOfEdges[cu] += numberOfEdges[cv] + 1;
		sz[cu] += sz[cv];
		relabel(v, cu);
	} else {
		numberOfEdges[cv] += numberOfEdges[cu] + 1;
		sz[cv] += sz[cu];
		relabel(u, cv);
	}
}

int32_t main () {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, m; cin >> n >> m;
	init();
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
		merge(a, b);
	}
	bool res = true;
	for (int i = 1; i <= n; ++i) {
		if (numberOfEdges[label[i]] != sz[label[i]] * (sz[label[i]] - 1) / 2) {
			res = false;
			break;
		}
	}

	res ? cout << "YES\n" : cout << "NO\n";
}
