#include <cstring>
#include <cstddef>
#include <ios>
#include <iostream>
#include <cinttypes>
#include <vector>
#include <queue>

#define int long long
using namespace std;

// indegree toposort dp
// 1. numerate all vertice with they indegree (indegree -> amount of edges coming in)
// 2. bfs iteration with toposort fulfilling
// 3.for every char

vector<int> adj[300001];
int indegree[300001];
int dp[300001];
vector<int> toposort;

int32_t main () {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, m; cin >> n >> m;
	string s; cin >> s;
	for (int i = 0; i < m; ++i) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		++indegree[y];
	}

	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		if (indegree[i] == 0)
			q.push(i);
	}

	int cnt = 0;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		toposort.push_back(x);
		++cnt;
		for (int y : adj[x]) {
			--indegree[y];
			if (indegree[y] == 0)
				q.push(y);
		}
	}

	if (cnt < n) {
		cout << "-1\n";
		return 0;
	}

	int res = 0;
	for (char ch = 'a'; ch <= 'z'; ++ch) {
		memset(dp, 0, sizeof(dp));
		for (int x : toposort) {
			if (s[x-1] == ch) ++dp[x];
			for (int y : adj[x]) {
				dp[y] = max(dp[y], dp[x]);
			}
			res = max(res, dp[x]);
		}
	}

	cout << res << '\n';
}
