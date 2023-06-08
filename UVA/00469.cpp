#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

typedef float f32;
typedef double f64;
typedef int32_t i32;
typedef int64_t i64;

using namespace std;

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

vector<string> grid;
bool visited[105][105];
int ans = 0;
void dfs(int x, int y) {
  if (x < 0 || y < 0 || x >= grid.size() || y >= grid.front().size())
    return;

  if (visited[x][y] || grid[x][y] != 'W')
    return;

  visited[x][y] = true;
  for (int i = 0; i < 8; ++i)
    dfs(x + dx[i], y + dy[i]);

  ++ans;
}

i32 main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  scanf("%d", &t);
  getchar();
  getchar();
  while (t--) {
    grid.clear();

    string r;
    while (getline(cin, r) && !r.empty()) {
      if (r.front() != 'L' && r.front() != 'W') {
        int u, v;
        sscanf(r.c_str(), "%d%d", &u, &v);
        --u, --v;

        ans = 0;
        dfs(u, v);
        memset(visited, false, sizeof visited);

        printf("%d\n", ans);
      } else {
        grid.push_back(r);
      }
    }

    if (t != 0)
      printf("\n");
  }

  return 0;
}
