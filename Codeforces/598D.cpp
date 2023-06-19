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
vector<pair<i32, i32>> paintings;
vector<pair<i32, i32>> component;
vector<vector<i32>> amount;
void dfs(i32 x, i32 y) {
  if (x < 0 || y < 0 || x >= adj.size() || y >= adj.front().size())
    return;

  if (adj[x][y] == '*') {
    paintings.push_back({x, y});
    return;
  }

  if (visited[x][y])
    return;

  visited[x][y] = true;
  for (i32 i = 0; i < 4; ++i)
    dfs(x + dx[i], y + dy[i]);

  component.push_back({x, y});
}

i32 main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin.exceptions(cin.failbit);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  i32 n, m, k;
  cin >> n >> m >> k;
  adj.resize(n);
  for (i32 i = 0; i < n; ++i)
    cin >> adj[i];

  amount.assign(n, vector<i32>(m));

  visited.assign(n, vector<bool>(m, false));
  for (i32 i = 0; i < n; ++i)
    for (i32 j = 0; j < m; ++j) {
      component.clear();
      paintings.clear();

      dfs(i, j);
      for (auto [x, y] : component)
        amount[x][y] = paintings.size();
    }

  for (i32 i = 0; i < k; ++i) {
    i32 x, y;
    cin >> x >> y;
    --x, --y;
    cout << amount[x][y] << endl;
  }

  return 0;
}
