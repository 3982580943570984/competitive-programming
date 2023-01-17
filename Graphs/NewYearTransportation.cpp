#include <set>
#include <iostream>
#include <stdint.h>
#include <vector>

#define int long long
using namespace std;

set<int> adj[60003];
bool visited[60003];
set<int> was;
void dfs (int s) {
	if (!visited[s]) {
		visited[s] = true;
		for (auto v : adj[s]) {
			was.insert(v);
			dfs(v);
		}
	}
}

int32_t main () {

	int n, t; cin >> n >> t;
	vector<int> a(n-1); for (auto& elem : a) cin >> elem;
	for (int i = 0; i < n-1; ++i) {
		adj[i + 1].insert(i + a[i] + 1);
	}
	dfs(1);
	was.contains(t) ? cout << "YES\n" : cout << "NO\n";
}
