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

vector<set<i32>> adj;
vector<i32> vis;
string cmp;
void dfs (i32 s) {
  if (vis[s] == 3)
    return;

  vis[s] = 3;
  cmp.push_back(char(s + 'a'));
  for (auto& u : adj[s])
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

  i32 n; cin >> n;

  adj.assign(26, {});
  vis.assign(26, 0);
  
  for (i32 i = 0; i < n; ++i) {
    string str;
    cin >> str;

    for (i32 j = 1; j < str.size(); ++j) {
      adj[str[j - 1] - 'a'].insert(str[j] - 'a');
      vis[str[j] - 'a'] = 1;
    }

    if (!vis[str.front() - 'a'])
      vis[str.front() - 'a'] = 2;
  }

  for (i32 i = 0; i < 26; ++i)
    if (vis[i] == 2)
      dfs(i);

  cout << cmp;

  return 0;
}
