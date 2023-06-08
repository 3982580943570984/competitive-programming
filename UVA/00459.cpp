#include <bits/stdc++.h>
#include <string>
#include <vector>

typedef float f32;
typedef double f64;
typedef int32_t i32;
typedef int64_t i64;

using namespace std;

vector<i32> adj['Z' - 'A' + 1];
bool visited['Z' - 'A' + 1];
void dfs(int s) {
  if (!visited[s]) {
    visited[s] = true;
    for (const auto &u : adj[s])
      dfs(u);
  }
}

i32 main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  cin.ignore();

  while (t--) {
    cin.ignore();
    for (int i = 0; i < 'Z' - 'A' + 1; ++i)
      adj[i].clear();
    memset(visited, false, 'Z' - 'A' + 1);

    char l = cin.get();
    cin.ignore();

    while (cin.peek() != '\n' && cin.good()) {
      int u = cin.get() - 'A';
      int v = cin.get() - 'A';

      cin.ignore();

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    int count = 0;
    for (int i = 0; i < l - 'A' + 1; ++i) {
      if (!visited[i]) {
        ++count;
        dfs(i);
      }
    }

    t == 0 ? printf("%d\n", count) : printf("%d\n\n", count);
  }

  return 0;
}
