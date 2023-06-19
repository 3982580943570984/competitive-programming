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

vector<vector<i64>> dist;
void floyd_warshall() {
  for (i32 k = 0; k < dist.size(); ++k)
    for (i32 i = 0; i < dist.size(); ++i)
      for (i32 j = 0; j < dist.size(); ++j)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

i32 main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin.exceptions(cin.failbit);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  i32 n, m, q;
  cin >> n >> m >> q;

  dist.assign(n, vector<i64>(n));
  for (i32 i = 0; i < n; ++i)
    for (i32 j = 0; j < n; ++j)
      if (i == j)
        dist[i][j] = dist[j][i] = 0;
      else
        dist[i][j] = dist[j][i] = 1e18;

  for (i32 i = 0; i < m; ++i) {
    i64 u, v, w;
    cin >> u >> v >> w;
    --u, --v;

    dist[u][v] = dist[v][u] = min(dist[u][v], w);
  }

  floyd_warshall();

  for (i32 i = 0; i < q; ++i) {
    i32 u, v;
    cin >> u >> v;
    --u, --v;

    if (dist[u][v] == 1e18)
      cout << -1 << endl;
    else
      cout << dist[u][v] << endl;
  }

  return 0;
}
