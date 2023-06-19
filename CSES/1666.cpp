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
vector<vector<i32>> cmp;
void dfs(i32 cur) {
  if (vis[cur])
    return;

  vis[cur] = true;
  cmp.back().push_back(cur);
  for (auto &v : adj[cur])
    dfs(v);
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

  for (i32 i = 0; i < m; ++i) {
    i32 u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (i32 i = 0; i < n; ++i) {
    if (!vis[i]) {
      cmp.push_back({});
      dfs(i);
    }
  }

  cout << cmp.size() - 1 << endl;
  for (i32 i = 0; i < cmp.size() - 1; ++i)
    cout << cmp[i].front() + 1 << ' ' << cmp[i + 1].front() + 1 << endl;

  return 0;
}
