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
  i32 number_of_sets;

  void initialize(i32 n) {
    edges.assign(n, -1);
    number_of_sets = n;
  }

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
    --number_of_sets;

    return true;
  }
};

vector<tuple<i32, i32, i32>> edges;
i32 cost = 0, taken = 0;
void kruskal(i32 amount_of_vertices) {
  sort(edges.begin(), edges.end());

  DSU dsu;
  dsu.initialize(amount_of_vertices);

  vector<pair<i32, i32>> tree;

  for (auto &[w, u, v] : edges) {
    if (dsu.unite(u, v)) {
      if (v > u)
        swap(v, u);

      debug(w, u, v);

      tree.push_back({v, u});

      cost += w;
      ++taken;

      if (taken == amount_of_vertices - 1)
        break;
    }
  }

  if (dsu.number_of_sets != 1) {
    printf("Impossible\n");
    return;
  }

  sort(tree.begin(), tree.end(), [&](auto l, auto r) {
    if (l.first < r.first)
      return true;
    else if (l.first == r.first && l.second < r.second)
      return true;
    else
      return false;
  });

  printf("%d\n", cost);
  for (auto &[u, v] : tree)
    printf("%d %d\n", u, v);
}

i32 main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  i32 n, m;
  while (cin >> n >> m) {
    edges.clear();
    cost = 0;
    taken = 0;

    if (n == 0 && m == 0)
      break;

    for (i32 i = 0; i < m; ++i) {
      i32 u, v, w;
      cin >> u >> v >> w;
      edges.push_back({w, u, v});
    }

    debug(edges);

    kruskal(n);
  }

  return 0;
}
