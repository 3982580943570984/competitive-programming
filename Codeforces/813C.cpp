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
vector<vector<i32>> sizes;
void dfs(i32 s, i32 l) {
  if (vis[s])
    return;

  vis[s] = true;
  sizes.back()[s] = l;
  for (auto& u : adj[s])
    dfs(u, l + 1);
}

i32 main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin.exceptions(cin.failbit);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  i32 n, x; cin >> n >> x;

  --x;
  
  adj.assign(n, {});
  vis.assign(n, false);

  for (i32 i = 0; i < n - 1; ++i) {
    i32 u, v; cin >> u >> v; --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
 
  sizes.push_back({});
  sizes.back().assign(n, 0);
  dfs(0, 0);

  vis.assign(n, false);
  sizes.push_back({});
  sizes.back().assign(n, 0);
  dfs(x, 0);

  debug(sizes);

  i32 res = 0;
  for (i32 i = 0; i < n; ++i)
    if (sizes.front()[i] > sizes.back()[i])
      res = max(res, sizes.front()[i] * 2);

  cout << res << endl;

  return 0;
}
