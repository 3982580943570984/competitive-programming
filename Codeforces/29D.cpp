#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using namespace std;

template<typename T>
using vec = std::vector<T>;

template<typename Key, typename Hash = std::hash<Key>, typename KeyEqual = std::equal_to<Key>, typename Allocator = std::allocator<Key>>
using uset = std::unordered_set<Key, Hash, KeyEqual, Allocator>;

template<typename Key, typename Compare = std::less<Key>, typename Allocator = std::allocator<Key>>
using mset = std::multiset<Key, Compare, Allocator>;

template<typename Key, typename T, typename Compare = std::less<Key>, typename Allocator = std::allocator<std::pair<const Key, T>>>
using mmap = std::multimap<Key, T, Compare, Allocator>;

template<typename Key, typename Value, typename Hash = std::hash<Key>, typename KeyEqual = std::equal_to<Key>, typename Allocator = std::allocator<std::pair<const Key, Value>>>
using umap = std::unordered_map<Key, Value, Hash, KeyEqual, Allocator>;

typedef float f32;
typedef double f64;
typedef int32_t i32;
typedef int64_t i64;
typedef uint32_t u32;
typedef uint64_t u64;

vec<vec<i32>> g;
vec<i32> res { 1 };
bool dfs(i32 p, i32 u, i32 v) {
  if (u == v)
    return true;

  for (auto& n : g[u])
    if (n != p)
      if (dfs(u, n, v)) {
        res.push_back(u + 1);
        return true;
      }

  return false;
}

i32 main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin.exceptions(cin.failbit);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  i32 n; cin >> n;

  g.assign(n, {});

  for (i32 i = 0; i < n - 1; ++i) {
    i32 u, v; cin >> u >> v; --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vec<i32> leafs;
  for (i32 i = 1; i < n; ++i)
    if (g[i].size() == 1)
      leafs.push_back(i);

  i32 u = 0, v = 0;
  for (i32 i = 0; i < leafs.size(); ++i) {
    cin >> v; --v;
    dfs(-1, v, u);
    u = v;
  }

  dfs(-1, 0, u);

  if (res.size() != (2*n - 1))
    cout << -1 << endl;
  else
    for (auto& r : res)
      cout << r << ' ';

  return 0;
}
