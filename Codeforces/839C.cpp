#include <iomanip>
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
vector<bool> visited;
f64 result = 0.0;
void dfs(i32 s, i64 depth, f64 probability) {
  if (visited[s])
    return;

  visited[s] = true;

  i32 moves = 0;
  for (const auto &u : adj[s])
    if (!visited[u])
      ++moves;

  if (!moves) {
    result += depth * probability;
  } else {
    f64 new_probability = probability / moves;
    for (const auto &u : adj[s])
      dfs(u, depth + 1, new_probability);
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

  i32 n;
  cin >> n;
  adj.resize(n);
  visited.resize(n);
  for (i32 i = 0; i < n - 1; i++) {
    i32 u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(0, 0, 1);

  cout << setprecision(10) << result << endl;

  return 0;
}
