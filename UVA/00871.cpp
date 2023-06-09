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

i32 dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
i32 dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

vector<string> adj;
vector<vector<bool>> visited;
i32 sz = 0;
void dfs (i32 x, i32 y) {
  if (x < 0 || y < 0 || x >= adj.size() || y >= adj.front().size())
    return;

  if (visited[x][y] || adj[x][y] == '0')
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

  i32 t; cin >> t;
  cin.ignore();
  while (t--) {
    string str;
    while(getline(cin, str) && !str.empty())
      adj.push_back(str);

    visited.assign(adj.size(), vector<bool>(adj.front().size()));

    i32 ans = 0;
    for (i32 i = 0; i < adj.size(); ++i)
      for (i32 j = 0; j < adj.front().size(); ++j)
        if (adj[i][j] == '1') {
          sz = 0;
          dfs(i, j);
          ans = max(ans, sz);
        }

    printf("%d\n", ans);
  }

  return 0;
}
