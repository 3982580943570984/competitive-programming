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
i32 ans = 0;
void dfs (i32 x, i32 y) {
  if (x < 0 || y < 0 || x >= adj.size() || y >= adj.front().size())
    return;

  if (visited[x][y] || adj[x][y] == '#')
    return;

  if (adj[x][y] == 'G')
    ++ans;

  visited[x][y] = true;

  for (i32 i = 0; i < 4; ++i)
    if (!(x + dx[i] < 0 || y + dy[i] < 0 ||
        x + dx[i] >= adj.size() || y + dy[i] >= adj.front().size()))
      if (adj[x + dx[i]][y + dy[i]] == 'T')
        return;

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

  i32 w, h;
  while (cin >> w >> h) {

    adj.resize(h);
    visited.assign(h, vector<bool>(w));

    for (auto& row : adj)
      cin >> row;

    ans = 0;
    for (i32 i = 0; i < h; ++i)
      for (i32 j = 0; j < w; ++j)
        if (adj[i][j] == 'P')
          dfs(i, j);

    printf("%d\n", ans);
  }

  return 0;
}
