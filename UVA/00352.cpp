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

i32 dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
i32 dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

vector<string> adj;
vector<vector<bool>> visited;
void dfs (i32 x, i32 y) {
  if (x < 0 || y < 0 || x >= adj.size() || y >= adj.front().size())
    return;

  if (visited[x][y] || adj[x][y] != '1')
    return;

  visited[x][y] = true;
  for (i32 i = 0; i < 8; ++i)
    dfs(x + dx[i], y + dy[i]);
}

i32 main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  i32 rows;
  i32 counter = 0;
  while (cin >> rows) {
    adj.resize(rows);
    visited.assign(rows, vector<bool>(rows));

    for (i32 i = 0; i < rows; ++i)
      cin >> adj[i];

    i32 ans = 0;
    for (i32 i = 0; i < adj.size(); ++i)
      for (i32 j = 0; j < adj[i].size(); ++j)
        if (adj[i][j] == '1' && !visited[i][j])
          dfs(i, j), ++ans;

    printf("Image number %d contains %d war eagles.\n", ++counter, ans);
  }

  return 0;
}
