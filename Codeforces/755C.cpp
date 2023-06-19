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
void dfs(i32 s) {
  if (visited[s])
    return;

  visited[s] = true;
  for (const auto &u : adj[s])
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

  i32 n;
  cin >> n;

  adj.assign(n, {});
  visited.assign(n, false);

  for (i32 i = 0; i < n; ++i) {
    i32 p;
    cin >> p;
    --p;
    adj[p].push_back(i);
    adj[i].push_back(p);
  }

  i32 result = 0;
  for (i32 i = 0; i < n; ++i) {
    if (!visited[i]) {
      ++result;
      dfs(i);
    }
  }

  cout << result << endl;

  return 0;
}
