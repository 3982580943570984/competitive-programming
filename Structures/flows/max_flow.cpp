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

const i64 inf = 1e18; // large enough
typedef tuple<i32, i64, i64> edge;

class max_flow {
private:
  i32 V;
  vec<edge> edges;
  vec<vec<i32>> g;
  vec<i32> d, last;
  vec<pair<i32, i32>> p;

  bool bfs(i32 s, i32 t) { // find augmenting path
    d.assign(V, -1);
    d[s] = 0;

    queue<i32> q({s});
    p.assign(V, {-1, -1}); // record BFS sp tree

    while (!q.empty()) {
      i32 u = q.front();
      q.pop();

      if (u == t)
        break; // stop as sink t reached

      for (auto &idx : g[u]) {                         // explore neighbors of u
        auto &[v, cap, flow] = edges[idx];             // stored in EL[idx]
        if ((cap - flow > 0) && (d[v] == -1))          // positive residual edge
          d[v] = d[u] + 1, q.push(v), p[v] = {u, idx}; // 3 lines in one!
      }
    }

    return d[t] != -1; // has an augmenting path
  }

  i64 send_one_flow(i32 s, i32 t, i64 f = inf) { // send one flow from s->t
    if (s == t)
      return f; // bottleneck edge f found

    auto &[u, idx] = p[t];
    auto &cap = get<1>(edges[idx]), &flow = get<2>(edges[idx]);

    i64 pushed = send_one_flow(s, u, min(f, cap - flow));
    flow += pushed;

    auto &rflow = get<2>(edges[idx ^ 1]); // back edge
    rflow -= pushed;                      // back flow

    return pushed;
  }

  i64 dfs(i32 u, i32 t, i64 f = inf) { // traverse from s->t
    if ((u == t) || (f == 0))
      return f;

    for (i32 &i = last[u]; i < (i32)g[u].size(); ++i) { // from last edge
      auto &[v, cap, flow] = edges[g[u][i]];

      if (d[v] != d[u] + 1)
        continue; // not part of layer graph

      if (i64 pushed = dfs(v, t, min(f, cap - flow))) {
        flow += pushed;

        auto &rflow = get<2>(edges[g[u][i] ^ 1]); // back edge
        rflow -= pushed;

        return pushed;
      }
    }

    return 0;
  }

public:
  max_flow(i32 initialV) : V(initialV) {
    g.assign(V, {});
    edges.clear();
  }

  void add_edge(i32 u, i32 v, i64 w, bool directed = true) {
    if (u == v)
      return; // safeguard: no self loop

    edges.emplace_back(v, w, 0);           // u->v, cap w, flow 0
    g[u].push_back((i32)edges.size() - 1); // remember this index

    edges.emplace_back(u, directed ? 0 : w, 0); // back edge
    g[v].push_back((i32)edges.size() - 1);      // remember this index
  }

  // an O(V*E^2) algorithm
  i64 edmonds_karp(i32 s, i32 t) {
    i64 mf = 0;

    while (bfs(s, t)) {
      i64 f = send_one_flow(s, t); // find and send 1 flow f
      if (f == 0)
        break;
      mf += f;
    }

    return mf;
  }

  // an O(V^2*E) algorithm
  i64 dinic(i32 s, i32 t) {
    i64 mf = 0;

    while (bfs(s, t)) {
      last.assign(V, 0);        // important speedup
      while (i64 f = dfs(s, t)) // exhaust blocking flow
        mf += f;
    }

    return mf;
  }
};

i32 main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin.exceptions(cin.failbit);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  i32 n, k;
  cin >> n >> k;

  max_flow mf(n);
  for (i32 i = 0; i < k; ++i) {
    i32 u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    mf.add_edge(u, v, w, false);
  }

  cout << mf.edmonds_karp(0, n - 1) << '\n';

  return 0;
}
