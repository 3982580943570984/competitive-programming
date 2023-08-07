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

vec<vec<i32>> g;
vec<bool> vis;
vec<i32> ts;
void dfs(i32 u) {
  if (vis[u])
    return;

  vis[u] = true;
  for (auto &v : g[u]) {
    dfs(v);
  }

  ts.push_back(u);
}

void toposort() {
  vis.assign(g.size(), false);
  ts.clear();

  for (i32 i = 0; i < g.size(); ++i)
    dfs(i);

  reverse(ts.begin(), ts.end());
}

i32 main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin.exceptions(cin.failbit);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  return 0;
}