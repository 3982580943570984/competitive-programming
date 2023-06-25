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
i32 ml = 0, p = 0;
void dfs(i32 s, i32 l = 0) {
  if (vis[s])
    return;

  if (l > ml)
    ml = l, p = s;

  vis[s] = true;
  for (auto& u : adj[s])
    dfs(u, l + 1);
}

i32 main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin.exceptions(cin.failbit);

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  i32 n; cin >> n;

  i32 res = 0;
  for (i32 i = 0; i < n; ++i) {
    i32 x; cin >> x;

    adj.assign(x, {});
    vis.assign(x, false);

    for (i32 j = 0; j < x - 1; ++j) {
      i32 u, v; cin >> u >> v; --u, --v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    dfs(0);

    ml = 0;
    vis.assign(n, false);

    dfs(p);

    res += ml;
    ml = 0;
  }

  cout << res << endl;

  return 0;
}
