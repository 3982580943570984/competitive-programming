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

umap<int, vector<i32>> g;
umap<int, bool> vis;
vec<i32> rt;
void dfs(i32 s) {
  if (vis[s])
    return;

  vis[s] = true;
  rt.push_back(s);
  for (auto& u : g[s])
    dfs(u);
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

  for (i32 i = 0; i < n; ++i) {
    i32 u, v; cin >> u >> v; --u, --v;
    vis[u] = vis[v] = false;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  i32 strt = 0;
  for (auto& [u, a] : g)
    if (a.size() == 1) {
      strt = u;
      break;
    }

  dfs(strt);

  for (auto& u : rt)
    cout << u + 1 << ' ';
  cout << endl;

  return 0;
}
