#include <ios>
#include <iostream>
#include <stdint.h>
#include <vector>

#define int long long
using namespace std;

vector<int> adj[2005];
int res = 0;
void dfs (int s, int d = 1) {
	res = max(res, d);
	for (auto& u : adj[s]) {
		dfs(u, d + 1);
	}
}

int32_t main () {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		if (x != -1) {
			adj[x].push_back(i);
		}
	}
	for (int i = 1; i <= n; ++i) dfs(i);
	cout << res << endl;
}
