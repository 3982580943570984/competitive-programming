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

struct DSU {
  vector<i64> edges;
  i64 number_of_sets;

  void initialize(i64 n) {
    edges.assign(n, -1);
    number_of_sets = n;
  }

  i64 find(i64 x) { return edges[x] < 0 ? x : edges[x] = find(edges[x]); }

  bool same(i64 a, i64 b) { return find(a) == find(b); }

  i64 size(i64 x) { return -edges[find(x)]; }

  bool unite(i64 a, i64 b) {
    a = find(a), b = find(b);

    if (a == b)
      return false;

    if (edges[a] > edges[b])
      swap(a, b);

    edges[a] += edges[b];
    edges[b] = a;
    --number_of_sets;

    return true;
  }
};

vector<tuple<i64, i64, i64>> edges;
i64 cost = 0, taken = 0;
void kruskal(i32 amount_of_vertices) {
  sort(edges.begin(), edges.end());

  DSU dsu;
  dsu.initialize(amount_of_vertices);

  for (auto &[w, u, v] : edges) {
    if (dsu.unite(u, v)) {
      cost += w;
      ++taken;

      if (taken == amount_of_vertices - 1)
        break;
    }
  }

  if (dsu.number_of_sets != 1)
    cout << "IMPOSSIBLE" << endl;
  else
    cout << cost << endl;
}

i32 main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin.exceptions(cin.failbit);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  i64 n, m;
  cin >> n >> m;
  for (i32 i = 0; i < m; ++i) {
    i64 u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    edges.push_back({w, u, v});
  }

  kruskal(n);

  return 0;
}
