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
vector<i32> chrctrs;
void dfs(i32 s) {
  if (vis[s])
    return;

  vis[s] = true;
  cmps.back().push_back(chrctrs[s]);
  for (auto u : adj[s])
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

  i32 n, m; cin >> n >> m;
  
  adj.assign(n, {});
  vis.assign(n, false);
  chrctrs.assign(n, 0);

  for (i32 i = 0; i < chrctrs.size(); ++i)
    cin >> chrctrs[i];

  for (i32 i = 0; i < m; ++i) {
    i32 u, v; cin >> u >> v; --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (i32 i = 0; i < n; ++i) {
    if (!vis[i]) {
      cmps.push_back({});
      dfs(i);
    }
  }

  i64 res = 0;
  for (auto cmp : cmps)
    res += *min_element(cmp.begin(), cmp.end());

  cout << res << endl;

  return 0;
}
