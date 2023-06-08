#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using namespace std;

typedef float f32;
typedef double f64;
typedef int32_t i32;
typedef int64_t i64;

vector<vector<i32>> adj;
vector<bool> visited;
i32 ans = 0;
void dfs (int s) {
  if (visited[s]) return;

  visited[s] = true;
  for (const auto& u : adj[s])
      dfs(u);

  ++ans;
}

i32 main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  while (true) {
    i32 n, m; cin >> n >> m;
    if (n == 0 && m == 0)
      break;

    adj.resize(n); adj.clear();
    visited.resize(n); visited.clear();

    i64 val = INT_MIN;
    vector<pair<i64, pair<i64, i64>>> roads(m);
    for (i32 i = 0; i < m; ++i) {
      i64 u, v, w; cin >> u >> v >> w; --u, --v;
      val = max(val, w);
      roads.push_back({w, {u, v}});
    }

    sort(roads.begin(), roads.end(), [&](pair<i64, pair<i64, i64>> l, pair<i64, pair<i64, i64>> r) {
      return l.first > r.first;
    });

    debug(roads);

    for (auto& road : roads) {
      i64 w = road.first;
      i64 u = road.second.first;
      i64 v = road.second.second;

      if (w < val) break;

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    i32 res = 0;
    for (i32 i = 0; i < n; ++i) {
      ans = 0;
      dfs(i);
      res = max(res, ans);
    }

    cout << res << '\n';
  }

  return 0;
}
