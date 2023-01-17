#include <ios>
#include <iostream>
#include <stdint.h>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>

#define int long long
using namespace std;

vector<int> adj[500005];
bool visited[500005];
vector<int> component;
void dfs (int s) {
	if (!visited[s]) {
		component.push_back(s);
		visited[s] = true;
		for (auto v : adj[s]) {
			dfs(v);
		}
	}
}

int32_t main () {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int k; cin >> k;
		vector<int> fr;
		
		for (int j = 0; j < k; ++j) {
			int f; cin >> f;
			fr.push_back(f);
		}
		
		for (int j = 0; j < k - 1; ++j) {
			adj[fr[j]].push_back(fr[j + 1]);
			adj[fr[j + 1]].push_back(fr[j]);
		}
	}
	
	vector<int> us(n);
	for (int i = 1; i <= n; ++i) {
		dfs(i);
		if (!component.empty()) {
			for (auto c : component) us[c-1] = component.size();
			component.clear();
		}
	}

	for (auto u : us)
		cout << u << ' ';
	cout << endl;
}
