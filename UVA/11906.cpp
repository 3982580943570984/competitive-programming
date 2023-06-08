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

vector<vector<bool>> visited;
vector<vector<bool>> water;
i32 r, c, m, n;
i32 odd = 0, even = 0;
void dfs (i32 x, i32 y) {
  if (visited[x][y]) return;
  visited[x][y] = true;

  set<pair<i32, i32>> oth;
  for (auto& dx : { -n, n })
    for (auto& dy : { -m, m })
      if (x+dx >= 0 && x+dx < r && y+dy >= 0 && y+dy < c)
        if (!water[x+dx][y+dy])
          oth.insert({x+dx, y+dy});

  for (auto& dx : { -m, m })
    for (auto& dy : { -n, n })
      if (x+dx >= 0 && x+dx < r && y+dy >= 0 && y+dy < c)
        if (!water[x+dx][y+dy])
          oth.insert({x+dx, y+dy});

  for (auto& [x, y] : oth)
    dfs(x, y);

  oth.size() & 1 ? ++odd : ++even;
}

i32 main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  i32 t; cin >> t;
  i32 count = 1;
  while (t--) {
    cin >> r >> c >> m >> n;

    visited.assign(r + 1, vector<bool>(c + 1, false));
    water.assign(r + 1, vector<bool>(c + 1, false));

    i32 w; cin >> w;
    for (i32 i = 0; i < w; ++i) {
      i32 x, y; cin >> x >> y; water[x][y] = true;
    }

    odd = 0, even = 0;
    dfs(0, 0);

    printf("Case %d: %d %d\n", count++, even, odd);
  }

  return 0;
}
