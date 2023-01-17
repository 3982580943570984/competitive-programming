#include <cstddef>
#include <ios>
#include <iostream>
#include <stdint.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define int long long
using namespace std;

set<int> adj[200005];
bool visited[200005];

vector<int> components;
vector<int> socks_colors;

void dfs (int s) {
	if (!visited[s]) {
		visited[s] = true;
		components.push_back(socks_colors[s-1]);
		for (auto v : adj[s]) {
			dfs(v);
		}
	}
}

int32_t main () {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	int n, m, k; cin >> n >> m >> k;
	socks_colors.resize(n); for (auto& elem : socks_colors) cin >> elem;

	for (int i = 0; i < m; ++i) {
		int left, right; cin >> left >> right;
		adj[left].insert(right);
		adj[right].insert(left);
	}

	//for (auto s : socks_colors) {cout << s << ' ';} cout << endl;
	//for (auto v : adj[1]) {cout << v << ' ';} cout << endl;
	//for (auto v : adj[2]) {cout << v << ' ';} cout << endl;

	int _m = 0;
	for (int i = 1; i <= n; ++i) {
		components.clear();
		dfs(i);
		sort(components.begin(), components.end());
		map<int, int> colors; for (auto e : components) { ++colors[e]; }
		if (components.size() > 0) {
			int wh = 0;
			for (auto [k, v] : colors) wh = max(wh, v);
			_m += components.size() - wh;
		}
	}
	cout << _m << endl;

}
