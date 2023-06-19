#include <vector>
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

  void initialize(i32 n) {
    edges.assign(n, -1);
  }

  i32 find(i32 x) {
    return edges[x] < 0 ? x : edges[x] = find(edges[x]);
  }

  bool same(i32 a, i32 b) {
    return find(a) == find(b);
  }

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

vector<vector<i32>> adj;
vector<tuple<i32, i32, i32>> edges;
i32 cost = 0, taken = 0;
void kruskal() {
  // sort all edges by weight
  sort(edges.begin(), edges.end());

  // create disjoint set for each vertice
  DSU dsu; dsu.initialize(adj.size());

  for (auto& [w, u, v] : edges) {
    if (dsu.same(u, v))
      continue;

    cost += w;
    dsu.unite(u, v);
    ++taken;

    if (taken == adj.size() - 1)
      break;
  }
}
