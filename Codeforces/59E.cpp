#include <limits>
#include <queue>
#include <unordered_set>
#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using namespace std;

typedef float f32;
typedef double f64;
typedef int32_t i32;
typedef int64_t i64;
typedef uint32_t u32;
typedef uint64_t u64;

vector<vector<i32>> adj;
vector<bool> vis;
vector<i32> dist;
vector<vector<i32>> par;
set<tuple<i32, i32, i32>> trplts;
void bfs(i32 strt) {
  queue<pair<i32, i32>> q;
  q.push({strt, strt});
  vis[strt] = true;

  while (!q.empty()) {
    int p = q.front().first, u = q.front().second;
    q.pop();
    for (auto &v : adj[u]) {
      if (!vis[v]) {
        debug(p + 1, u + 1, v + 1);
      }
      if (!vis[v] && !trplts.contains({p, u, v})) {
        vis[v] = true;
        q.push({u, v});
        dist[v] = dist[u] + 1;
        par[v].push_back(u);
      }

      if (trplts.contains({p, u, v})) {
        vis[u] = false;
      }
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

  i32 n, m, k;
  cin >> n >> m >> k;

  adj.assign(n, {});
  vis.assign(n, false);
  dist.assign(n, 0);
  par.assign(n, {});

  for (i32 i = 0; i < m; ++i) {
    i32 u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (i32 i = 0; i < k; ++i) {
    i32 a, b, c;
    cin >> a >> b >> c;
    --a, --b, --c;
    trplts.insert({a, b, c});
  }

  bfs(0);

  debug(dist);

  if (dist.back() == 0) {
    cout << -1 << endl;
  } else {
    cout << dist.back() << endl;

    debug(par);

    vector<i32> path{n - 1};
    int i = n - 1;
    while (!par[i].empty()) {
      path.push_back(par[i].back());
      par[i].pop_back();
      i = path.back();
    }

    reverse(path.begin(), path.end());

    for (auto v : path)
      cout << v + 1 << ' ';
  }

  return 0;
}
