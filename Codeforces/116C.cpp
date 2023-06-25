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
i32 ml = 1;
void dfs(i32 s, i32 l = 1) {
  if (l > ml) ml = l;

  for (auto& u : adj[s])
    dfs(u, l + 1);
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
  
  adj.assign(n, {});
  
  for (i32 i = 0; i < n; ++i) {
    i32 v; cin >> v;
    
    if (v == -1)
      continue;

    --v;

    adj[v].push_back(i);
  }

  for (i32 i = 0; i < n; ++i)
    dfs(i);


  cout << ml << endl;

  return 0;
}
