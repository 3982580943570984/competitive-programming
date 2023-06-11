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
  vector<i32> edges;

  void initialize(i32 n) { edges.assign(n, -1); }

  i32 find(i32 x) { return edges[x] < 0 ? x : edges[x] = find(edges[x]); }

  bool same(i32 a, i32 b) { return find(a) == find(b); }

  i32 size(i32 x) { return -edges[find(x)]; }

  bool unite(i32 a, i32 b) {
    a = find(a), b = find(b);

    if (a == b)
      return false;

    if (edges[a] > edges[b])
      swap(a, b);

    edges[a] += edges[b];
    edges[b] = a;

    return true;
  }
};

vector<tuple<i32, i32, i32>> edges;
i32 cost = 0, taken = 0;
void kruskal(i32 amount_of_vertices) {
  sort(edges.begin(), edges.end());

  DSU dsu;
  dsu.initialize(amount_of_vertices);

  vector<pair<i32, i32>> vertices;
  for (auto &[w, u, v] : edges) {
    if (dsu.unite(u, v)) {
      vertices.push_back({u, v});
      cost += w;
      ++taken;

      if (taken == amount_of_vertices - 1)
        break;
    }
  }

  printf("%d\n", cost);
  for (auto &[u, v] : vertices)
    printf("%d %d\n", u, v);
}

i32 main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  i32 n, k;
  cin >> n >> k;
  vector<string> vertices(n);
  for (auto &vertice : vertices)
    cin >> vertice;

  for (i32 i = 0; i < n; ++i)
    for (i32 j = i + 1; j < n; ++j) {
      i32 counter = 0;
      for (i32 h = 0; h < k; ++h)
        if (vertices[i][h] != vertices[j][h])
          ++counter;

      edges.push_back({counter, i, j});
    }

  kruskal(n);

  return 0;
}
