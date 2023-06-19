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
vector<bool> visited;
i32 max_depth = 0, specified_vertice = 0;
void dfs(i32 s, i32 depth) {
  if (visited[s])
    return;

  debug(s);

  visited[s] = true;

  if (depth > max_depth) {
    max_depth = depth;
    specified_vertice = s;
  }

  for (const auto &u : adj[s])
    dfs(u, depth + 1);
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
  for (i32 i = 0; i < n - 1; ++i) {
    i32 u, v;
    cin >> u >> v;
    --u, --v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  visited.assign(n, false);
  dfs(0, 0);
  debug(specified_vertice, max_depth);
  max_depth = 0;

  visited.assign(n, false);
  dfs(specified_vertice, 0);
  debug(specified_vertice, max_depth);

  cout << max_depth << endl;

  return 0;
}
