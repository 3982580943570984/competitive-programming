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

i32 dx[] = {0, 0, 1, -1};
i32 dy[] = {-1, 1, 0, 0};

vector<string> adj;
vector<vector<bool>> visited;
set<pair<i32, i32>> component;
void dfs(i32 x, i32 y) {
  if (x < 0 || y < 0 || x >= adj.size() || y >= adj.front().size())
    return;

  if (visited[x][y] || adj[x][y] == '#')
    return;

  visited[x][y] = true;
  for (i32 i = 0; i < 4; ++i)
    dfs(x + dx[i], y + dy[i]);

  component.insert({x, y});
}

i32 main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin.exceptions(cin.failbit);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  i32 t;
  cin >> t;
  while (t--) {
    component.clear();

    i32 n, m;
    cin >> n >> m;

    adj.assign(n, "");
    for (i32 i = 0; i < n; ++i)
      cin >> adj[i];

    visited.assign(n, vector<bool>(m));

    debug(adj);

    for (i32 i = 0; i < n; ++i)
      for (i32 j = 0; j < m; ++j)
        if (adj[i][j] == 'B')
          for (i32 k = 0; k < 4; ++k)
            if (!(i + dx[k] < 0 || j + dy[k] < 0 || i + dx[k] >= adj.size() ||
                  j + dy[k] >= adj.front().size()))
              if (adj[i + dx[k]][j + dy[k]] != 'G' &&
                  adj[i + dx[k]][j + dy[k]] != 'B')
                adj[i + dx[k]][j + dy[k]] = '#';

    debug(adj);

    set<pair<i32, i32>> points;
    for (i32 i = 0; i < n; ++i)
      for (i32 j = 0; j < m; ++j)
        if (adj[i][j] == 'G') {
          points.insert({i, j});
          adj[i][j] = '.';
        }

    dfs(n - 1, m - 1);

    bool result = true;
    if (includes(component.begin(), component.end(), points.begin(),
                 points.end())) {
      for (auto &[x, y] : points)
        for (i32 k = 0; k < 4; ++k)
          if (!(x + dx[k] < 0 || y + dy[k] < 0 || x + dx[k] >= adj.size() ||
                y + dy[k] >= adj.front().size()))
            if (adj[x + dx[k]][y + dy[k]] == 'B')
              result = false;
    } else {
      result = false;
    }

    cout << (result ? "Yes" : "No") << endl;
  }

  return 0;
}
