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

vector<bool> vis;
vector<vector<i32>> adj;
vector<i32> clrs;
bool impossible = false;
void dfs(i32 par, i32 cur, i32 clr) {
  if (vis[cur])
    return;

  vis[cur] = true;
  clrs[cur] = clr;
  for (auto &v : adj[cur]) {
    if (v != par && clrs[v] == clrs[cur]) {
      impossible = true;
      return;
    }
    dfs(cur, v, clr == 1 ? 2 : 1);
  }
}

i32 main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin.exceptions(cin.failbit);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  i32 n, m;
  cin >> n >> m;

  adj.assign(n, {});
  vis.assign(n, false);
  clrs.assign(n, 0);

  for (i32 i = 0; i < m; ++i) {
    i32 u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (i32 i = 0; i < n; ++i)
    dfs(i, i, 1);

  if (impossible)
    cout << "IMPOSSIBLE" << endl;
  else {
    for (auto clr : clrs)
      cout << clr << " ";
    cout << endl;
  }

  return 0;
}
