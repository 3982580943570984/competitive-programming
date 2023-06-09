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

i32 dx[] = { 0, 0, 1, -1 };
i32 dy[] = { -1, 1, 0, 0 };

vector<string> adj;
vector<vector<bool>> visited;
bool component = false;
void dfs (i32 x, i32 y) {
  if (x < 0 || y < 0 || x >= adj.size() || y >= adj.size())
    return;

  if (visited[x][y] || adj[x][y] != 'x' && adj[x][y] != '@')
    return;

  if (adj[x][y] == 'x')
    component = true;

  visited[x][y] = true;
  for (i32 i = 0; i < 4; ++i)
    dfs(x + dx[i], y + dy[i]);
}

i32 main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  i32 t; cin >> t;
  i32 counter = 0;
  while (t--) {
    i32 n; cin >> n;

    adj.resize(n);
    visited.assign(n, vector<bool>(n));

    for (auto& row : adj)
      cin >> row;

    i32 ans = 0;
    for (i32 i = 0; i < n; ++i)
      for (i32 j = 0; j < n; ++j)
        if (adj[i][j] == 'x') {
          component = false;
          dfs(i, j);

          if (component)
            ++ans;
        }

    printf("Case %d: %d\n", ++counter, ans);
  }

  return 0;
}
