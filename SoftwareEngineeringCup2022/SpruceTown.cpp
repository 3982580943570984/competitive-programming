#include <cstring>
#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

#define int long long
using namespace std;

vector<int> adj[1005];
bool visited[1005];
int l = 0, r = 0;
void dfs (int s, int d, set<int>& m) {
	if (!visited[s]) {
		visited[s] = true;
		if (m.contains(s) && m.size() == 1) visited[s] = false;
		if (m.contains(s)) { !l ? l = d : r = d; return; }
		for (auto u : adj[s]) {
			dfs(u, d + 1, m);
		}
	}
}

unordered_set<int> cutting;
int depth = -1;
int link = 0;
void cut (int s, int d, set<int>& m) {
	if (!visited[s]) {
		visited[s] = true;
		cutting.insert(s);
		if (m.contains(s)) m.erase(s);
		if (m.empty()) { depth = d; return; }
		if (adj[s].size() == 3) { link = s; return; }
		for (auto u : adj[s]) {
			cut(u, d + 1, m);
		}
	}
}

// get left first and right first
// cycle size - max(left, right) + cutting.size();

int32_t main () {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n; cin >> n;
	set<int> must;
	for(int i = 0; i < n; ++i) {
		int e; cin >> e;
		if (e > 0) must.insert(i + 1);
	}
	if (must.empty()) { cout << 0 << endl; return 0; }
	for (int i = 0; i < n; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i < 1005; ++i) {
		if (adj[i].size() == 1) {
			cut(i, 1, must);
			break;
		}
	}
	if (depth != -1) {
		cout << depth - 1 << endl;
	} else {
		visited[link] = false;
		dfs(link, 0, must);
		if (must.size() == 1) {
			cout << min(l, r) + cutting.size() - 1 << endl;
		} else {
			cout << (n - max(l, r)) << endl;
		}
	}
}
