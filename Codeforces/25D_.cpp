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
vec<vec<i32>> cmps;
set<pair<i32, i32>> usls;
void dfs(i32 p, i32 u) {
  if (vis[u]) {
    if (p != 0) {
      if (p > u) {
        swap(p, u);
      }
      usls.insert({ p + 1, u + 1 });
    }
    return;
  }

  vis[u] = true;
  cmps.back().push_back(u + 1);
  for (auto& v : g[u])
    if (v != p)
      dfs(u, v);
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

  for (i32 i = 0; i < n - 1; ++i) {
    i32 u, v; cin >> u >> v; --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  for (i32 i = 0; i < n; ++i)
    if (!vis[i]) {
      cmps.push_back({});
      dfs(0, i);
    }

  if (cmps.size() == 1) {
    cout << 0 << endl;
  } else {
      cout << cmps.size() - 1 << endl;
      debug(cmps);
      debug(usls);
      debug(usls.size(), cmps.size());
      vec<pair<i32, i32>> usls_ (usls.begin(), usls.end());
      for (i32 i = 0; i < usls_.size(); ++i) {
        i32 l = usls_[i].first, r = usls_[i].second;
        cout << l << ' ' << r << ' ' << cmps[i].front() << ' ' << cmps[i + 1].front() << endl;
      }
  }

  return 0;
}

