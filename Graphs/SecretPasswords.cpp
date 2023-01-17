#include <ios>
#include <set>
#include <iostream>
#include <stdint.h>
#include <vector>

#define int long long
using namespace std;

set<int> adj[30];
bool visited[30];
vector<int> component;
void dfs (int s) {
	if (!visited[s]) {
		visited[s] = true;
		component.push_back(s);
		for (auto& u : adj[s]) {
			dfs(u);
		}
	}
}

int32_t main () {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n; cin >> n;
	set<int> b;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		for (auto e : s) b.insert(e - 97);
		for (int j = 0; j < s.size() - 1; ++j) {
			adj[s[j]-97].insert(s[j+1]-97);
			adj[s[j+1]-97].insert(s[j]-97);
		}
	}
	int res = 0;
	for (auto e : b) {
		dfs(e);
		if (!component.empty()) {
			++res;
			component.clear();
		}
	}
	cout << res << endl;
}
