#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#ifdef LOCAL
#include "../algo/debug.h"
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

i32 iter_cnt, scc_cnt;
vec<i32> num, low, vis;
stack<i32> st;
vec<vec<i32>> sccs;
void tarjan(i32 u) {
  low[u] = num[u] = iter_cnt;
  ++iter_cnt;
  st.push(u);
  vis[u] = 1;
  for (auto &v : g[u]) {
    if (num[v] == UNVISITED)
      tarjan(v);
    if (vis[v])
      low[u] = min(low[u], low[v]);
  }

  if (low[u] == num[u]) {
    sccs.push_back({});
    ++scc_cnt;
    debug(st);
    while (true) {
      i32 v = st.top();
      st.pop();
      sccs.back().push_back(v);
      vis[v] = 0;
      if (u == v)
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

  g.assign(12, {});

  g[0].push_back(1);
  g[1].push_back(3);
  g[3].push_back(2);
  g[2].push_back(1);
  
  g[3].push_back(4);
  g[4].push_back(5);
  g[5].push_back(7);
  g[7].push_back(6);
  g[6].push_back(4);

  g[5].push_back(8);
  g[8].push_back(9);
  g[11].push_back(9);
  g[9].push_back(10);
  g[10].push_back(8);
  g[8].push_back(11);

  low.assign(g.size(), 0);
  num.assign(g.size(), UNVISITED);
  vis.assign(g.size(), false);

  while (!st.empty())
    st.pop();

  iter_cnt = scc_cnt = 0;
  for (i32 u = 0; u < g.size(); ++u)
    if (num[u] == UNVISITED)
      tarjan(u);

  debug(sccs);

  return 0;
}
