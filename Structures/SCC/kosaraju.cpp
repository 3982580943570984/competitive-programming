#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using namespace std;

template <typename T> using vec = std::vector<T>;

template <typename Key, typename Hash = std::hash<Key>,
          typename KeyEqual = std::equal_to<Key>,
          typename Allocator = std::allocator<Key>>
using uset = std::unordered_set<Key, Hash, KeyEqual, Allocator>;

template <typename Key, typename Compare = std::less<Key>,
          typename Allocator = std::allocator<Key>>
using mset = std::multiset<Key, Compare, Allocator>;

template <typename Key, typename T, typename Compare = std::less<Key>,
          typename Allocator = std::allocator<std::pair<const Key, T>>>
using mmap = std::multimap<Key, T, Compare, Allocator>;

template <typename Key, typename Value, typename Hash = std::hash<Key>,
          typename KeyEqual = std::equal_to<Key>,
          typename Allocator = std::allocator<std::pair<const Key, Value>>>
using umap = std::unordered_map<Key, Value, Hash, KeyEqual, Allocator>;

using f32 = float;
using f64 = double;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

enum { VISITED = -1, UNVISITED = -2, PROCESSED = -3 };

vec<vec<i32>> g, gt;
vec<i32> vis;

vec<i32> ts;
void kosaraju(i32 u, i32 pass) { // pass = 1 (original), 2 = transpose
  vis[u] = VISITED;
  vec<i32>& nbr = (pass == 1) ? g[u] : gt[u];
  for (auto& v : nbr)
    if (vis[v] == UNVISITED)
      kosaraju(v, pass);
  ts.push_back(u);
}

i32 main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin.exceptions(cin.failbit);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  ts.clear();
  vis.assign(g.size(), UNVISITED);
  for (i32 u = 0; u < g.size(); ++u)
    if (vis[u] == UNVISITED)
      kosaraju(u, 1);

  reverse(ts.begin(), ts.end());
  vis.assign(g.size(), UNVISITED);
  for (i32 u = 0; u < g.size(); ++u)
    if (vis[ts[u]] == UNVISITED)
      kosaraju(ts[u], 2);


  return 0;
}
