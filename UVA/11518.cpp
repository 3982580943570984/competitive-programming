#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

typedef float f32;
typedef double f64;
typedef int32_t i32;
typedef int64_t i64;

using namespace std;

vector<vector<i32>> adj;
vector<bool> visited;
int ans = 0;
void dfs(int s) {
  if (visited[s])
    return;

  visited[s] = true;
  for (const auto &u : adj[s])
    dfs(u);

  ++ans;
}

i32 main() {
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  i32 t;
  cin >> t;
  while (t--) {
    i32 n, m, l;
    cin >> n >> m >> l;

    adj.resize(n); adj.clear();
    visited.resize(n); visited.clear();

    for (i32 i = 0; i < m; ++i) {
      i32 u, v; cin >> u >> v; --u, --v;
      adj[u].push_back(v);
    }

    ans = 0;
    for (i32 i = 0; i < l; ++i) {
      i32 z; cin >> z; --z;
      dfs(z);
    }
    visited.assign(visited.size(), false);
    printf("%d\n", ans);
  }

  return 0;
}
