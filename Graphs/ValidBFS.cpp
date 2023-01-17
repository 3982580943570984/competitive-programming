#include <cstddef>
#include <ios>
#include <iostream>
#include <stdint.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

#define int long long
using namespace std;

vector<int> adj[200005];
bool visited[200005];
queue<int> q;

vector<int> res;

void bfs (int x) {
	visited[x] = true;
	q.push(x);
	while (!q.empty()) {
		int s = q.front(); q.pop(); res.push_back(s);
		for (auto u : adj[s]) {
			if (visited[u]) continue;
			visited[u] = true;
			q.push(u);
		}
	}
}

int32_t main () {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n; cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	vector<int> order(n+1);
	vector<int> _seq(n); for (int i = 0; auto& elem : _seq) { cin >> elem; order[elem] = i++;}
	for (int i = 1; i <= n; ++i) {
		sort(adj[i].begin(), adj[i].end(), [&order](auto l, auto r) {
			return order[l] < order[r];
		});
	}
	bfs(1);
	string(res.begin(), res.end()) == string(_seq.begin(), _seq.end()) ? cout << "Yes\n" : cout << "No\n";
}
