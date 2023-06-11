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

vector<tuple<u64, i64, i64>> edges;
u64 cost = 0, taken = 0;
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
  std::cin.exceptions(cin.failbit);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  i32 n;
  cin >> n;
  vector<tuple<i64, i64, i64, i64>> vertices(n);
  for (i32 i = 0; i < n; ++i) {
    i64 x, y, z;
    cin >> x >> y >> z;
    vertices[i] = {x, y, z, i};
  }

  sort(vertices.begin(), vertices.end(),
       [&](auto l, auto r) { return get<0>(l) > get<0>(r); });
  for (i32 i = 0; i < n - 1; ++i) {
    i64 x1 = get<0>(vertices[i]), x2 = get<0>(vertices[i + 1]);
    i64 i1 = get<3>(vertices[i]), i2 = get<3>(vertices[i + 1]);
    u64 w = abs(x2 - x1);
    edges.push_back({w, i1, i2});
  }

  sort(vertices.begin(), vertices.end(),
       [&](auto l, auto r) { return get<1>(l) > get<1>(r); });
  for (i32 i = 0; i < n - 1; ++i) {
    i64 y1 = get<1>(vertices[i]), y2 = get<1>(vertices[i + 1]);
    i64 i1 = get<3>(vertices[i]), i2 = get<3>(vertices[i + 1]);
    u64 w = abs(y2 - y1);
    edges.push_back({w, i1, i2});
  }

  sort(vertices.begin(), vertices.end(),
       [&](auto l, auto r) { return get<2>(l) > get<2>(r); });
  for (i32 i = 0; i < n - 1; ++i) {
    i64 z1 = get<2>(vertices[i]), z2 = get<2>(vertices[i + 1]);
    i64 i1 = get<3>(vertices[i]), i2 = get<3>(vertices[i + 1]);
    u64 w = abs(z2 - z1);
    edges.push_back({w, i1, i2});
  }

  kruskal(n);

  printf("%llu\n", cost);

  return 0;
}
