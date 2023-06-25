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
typedef uint32_t u32;
typedef uint64_t u64;

vector<vector<i32>> adj;
vector<bool> vis;
vector<vector<i32>> cmps;
void dfs(i32 s) {
  if (vis[s])
    return;

  vis[s] = true;
  cmps.back().push_back(s);
  for (auto& u : adj[s])
    dfs(u);
}

i32 main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin.exceptions(cin.failbit);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  i32 n; cin >> n;

  adj.assign(n, {});
  vis.assign(n, false);

  vector<tuple<i32, i32, i32>> edges(n);
  for (auto& [u, v, w] : edges) {
    cin >> u >> v >> w;
    --u, --v;
    
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  cmps.push_back({});
  dfs(0);
  vis.assign(n, false);

  cmps.push_back({});
  reverse(adj[0].begin(), adj[0].end());
  dfs(0);

  cmps.front().push_back(0);
  cmps.back().push_back(0);

  vector<set<pair<i32, i32>>> rds;
  for (auto& cmp : cmps) {
    rds.push_back({});
    for (i32 i = 1; i < cmp.size(); ++i)
      rds.back().insert({cmp[i], cmp[i-1]});
  }

  i32 res1 = 0;
  for (auto& [u, v, w] : edges)
    if (!rds.front().contains({u, v}))
      res1 += w;

  i32 res2 = 0;
  for (auto& [u, v, w] : edges)
    if (!rds.back().contains({u, v}))
      res2 += w;

  cout << min(res1, res2) << endl;

  return 0;
}
