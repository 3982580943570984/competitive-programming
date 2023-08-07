const i32 INF = 1e9;
vec<i32> l, r;
bool bipartite(i32 s) {
  queue<i32> q;
  q.push(s);
  vec<i32> color(g.size(), INF);
  color[s] = 0;
  l.push_back(s);
  bool is_bipartite = true;
  while (!q.empty() && is_bipartite) {
    i32 u = q.top();
    q.pop();
    for (auto &v : g[u]) {
      if (color[v] == INF) {
        color[v] = 1 - color[u];
        color[v] == 0 ? l.push_back(v) : r.push_back(v);
        q.push(v);
      } else if (color[v] == color[u]) {
        is_bipartite = false;
        break;
      }
    }
  }
  return is_bipartite;
}
