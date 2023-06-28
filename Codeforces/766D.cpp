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

struct DSU {
  vector<i32> edges;
  i32 number_of_sets;

  void initialize(i32 n) {
    edges.assign(n, -1);
    number_of_sets = n;
  }

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
	--number_of_sets;

    return true;
  }
} dsu;

vec<vec<pair<i32, i32>>> g;
vec<bool> vis;
vec<vec<i32>> cmps;
vec<i32> xrs;
void dfs(i32 p, i32 u, i32 w) {
  if (vis[u])
    return;

  vis[u] = true;
  xrs[u] = w;
  cmps.back().push_back(u);
  for (auto& [v, w_] : g[u])
    dfs(u, v, w ^ w_);
}

umap<string, i32> wrds;

i32 main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin.exceptions(cin.failbit);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  i32 n, m, q; cin >> n >> m >> q;

  for (i32 i = 0; i < n; ++i) {
    string wrd;
    cin >> wrd;
    wrds[wrd] = i;
  }

  g.assign(n, {});
  vis.assign(n, false);
  xrs.assign(n, -1);
  dsu.initialize(n);

  vec<string> ans;
  vec<tuple<string, string, i32>> rlts;
  for (i32 i = 0; i < m; ++i) {
    i32 t; cin >> t; --t;
    string fr, to; cin >> fr >> to;
    if (!dsu.unite(wrds[fr], wrds[to])) {
      ans.push_back("");
      rlts.push_back({ fr, to, t });
    } else {
      ans.push_back("YES");
      g[wrds[fr]].push_back({ wrds[to], t });
      g[wrds[to]].push_back({ wrds[fr], t });
    }
  }
  
  for (i32 i = 0; i < n; ++i)
    if (!vis[i]) {
      cmps.push_back({});
      dfs(i, i, 0);
    }

  for (i32 i = 0, j = 0; i < ans.size(); ++i) {
    if (ans[i].empty()) {
      if ((xrs[wrds[get<0>(rlts[j])]] ^ xrs[wrds[get<1>(rlts[j])]]) == get<2>(rlts[j]))
        cout << "YES" << endl;
      else
        cout << "NO" << endl;

      ++j;
    }
    else
      cout << ans[i] << endl;
  }

  for (i32 i = 0; i < q; ++i) {
    string u, v; cin >> u >> v;
    if (dsu.same(wrds[u], wrds[v])) {
      cout << (xrs[wrds[u]] ^ xrs[wrds[v]]) + 1 << endl;
    } else {
      cout << 3 << endl;
    }
  }

  return 0;
}
