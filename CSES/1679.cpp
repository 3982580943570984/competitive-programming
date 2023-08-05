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

vec<vec<i32>> g;
vec<i32> vis;
vec<i32> ts;
bool hase_cycle = false;
void dfs(i32 u) {
  vis[u] = VISITED;

  for (auto &v : g[u])
    if (vis[v] == UNVISITED)
      dfs(v);
    else if (vis[v] == VISITED)
      hase_cycle = true;

  vis[u] = PROCESSED;
  ts.push_back(u);
}

void toposort() {
  vis.assign(g.size(), UNVISITED);
  ts.clear();

  for (i32 u = 0; u < g.size(); ++u)
    if (vis[u] == UNVISITED)
      dfs(u);

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

  i32 n, m;
  cin >> n >> m;

  g.assign(n, {});
  for (i32 i = 0; i < m; ++i) {
    i32 u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
  }

  toposort();

  if (hase_cycle) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }

  for (auto &v : ts) {
    cout << v + 1 << ' ';
  }
  cout << '\n';

  return 0;
}
