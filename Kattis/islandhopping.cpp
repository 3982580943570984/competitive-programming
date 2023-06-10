#include <iomanip>
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

vector<tuple<f64, i32, i32>> edges;
f64 cost = 0;
i32 taken = 0;
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
}

i32 main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  i32 n;
  cin >> n;
  while (n--) {
    edges.clear();
    cost = 0;
    taken = 0;

    i32 m;
    cin >> m;

    vector<pair<f32, f32>> vertices(m);
    for (auto &vertice : vertices)
      cin >> vertice.first >> vertice.second;

    for (i32 i = 0; i < m; ++i)
      for (i32 j = i + 1; j < m; ++j) {
        f64 x1 = vertices[i].first, y1 = vertices[i].second;
        f64 x2 = vertices[j].first, y2 = vertices[j].second;
        f64 w = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        edges.push_back({w, i, j});
      }

    kruskal(m);

    printf("%.10f\n", cost);
  }

  return 0;
}
