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

using f32 = float;
using f64 = double;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

vec<vec<i32>> g;
vec<bool> vis;
vec<set<i32>> cmps;
void dfs (i32 u) {
  if (vis[u])
    return;

  vis[u] = true;
  cmps.back().insert(u);
  for (auto& v : g[u])
    dfs(v);
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
  vis.assign(n, false);

  vec<i32> r(n);
  for (i32 i = 0; i < n; ++i)
    cin >> r[i];

  vec<i32> d(n);
  for (i32 i = 0; i < n; ++i)
    cin >> d[i];

  for (i32 i = 0; i < n; ++i)
    for (i32 j = 0; j < n; ++j)
      if (abs(i - j) == d[i]) {
        g[i].push_back(j);
        g[j].push_back(i);
      }

  for (i32 i = 0; i < n; ++i) {
    if (!vis[i]) {
      cmps.push_back({});
      dfs(i);
    }
  }

  debug(cmps);

  vec<i32> t(n);
  for (i32 i = 0; i < cmps.size(); ++i)
    for (auto& u : cmps[i])
      t[u] = i;

  for (i32 i = 0; i < n; ++i)
    if (!cmps[t[i]].contains(r[i] - 1)) {
      cout << "NO" << endl;
      return 0;
    }

  cout << "YES" << endl;

  return 0;
}
