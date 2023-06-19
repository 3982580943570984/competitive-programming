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
vector<i32> clrs;
void dfs(i32 par, i32 cur, i32 clr) {
  if (vis[cur])
    return;

  vis[cur] = true;
  clrs[cur] = clr;
  for (auto &v : adj[cur])
    dfs(cur, v, clr == 1 ? 2 : 1);
}

i32 main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin.exceptions(cin.failbit);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  i32 n;
  cin >> n;

  adj.assign(n, {});
  vis.assign(n, false);
  clrs.assign(n, 0);

  for (i32 i = 0; i < n - 1; ++i) {
    i32 u, v;
    cin >> u >> v;
    --u, --v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(0, 0, 1);

  vector<i32> ones, twos;
  for (i32 i = 0; i < n; ++i)
    clrs[i] == 1 ? ones.push_back(i) : twos.push_back(i);

  debug(ones, twos);
  cout << ones.size() * twos.size() - n + 1 << endl;

  return 0;
}
