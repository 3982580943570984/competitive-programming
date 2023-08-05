#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
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

enum { UNVISITED = -1, VISITED = -2 };

vec<vec<i32>> g;
vec<i32> vis;

vec<i32> ts;
void toposort(i32 u) {
  vis[u] = VISITED;
  for (auto &v : g[u]) {
    if (vis[v] == UNVISITED) {
      toposort(v);
    }
  }
  ts.push_back(u);
}

vec<vec<i32>> gt;
void kosaraju(i32 u, i32 pass) { // pass = 1 (original), 2 (transpose)
  vis[u] = VISITED;
  vec<i32> &neighbor = (pass == 1) ? g[u] : gt[u];
  for (auto &v : neighbor)
    if (vis[v] == UNVISITED)
      kosaraju(v, pass);
  ts.push_back(u);
}

i32 main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin.exceptions(cin.failbit);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  g.assign('z' - 'a' + 1, {});
  gt.assign('z' - 'a' + 1, {});
  vis.assign('z' - 'a' + 1, UNVISITED);

  vec<string> names;
  while (true) {
    string name;
    cin >> name;
    if (name == "#")
      break;

    for (auto &e : name)
      e = tolower(e);
    names.push_back(name);
  }

  debug(names);
  debug(names.size());

  for (i32 i = 0; i < names.size() - 1; ++i) {
    auto l = names[i], r = names[i + 1];
    for (u32 j = 0; j < min(l.size(), r.size()); ++j) {
      if (l[j] != r[j]) {
        g[l[j] - 'a'].push_back(r[j] - 'a');
        gt[r[j] - 'a'].push_back(l[j] - 'a');
        break;
      }
    }
  }

  vis.assign('z' - 'a' + 1, UNVISITED);
  for (i32 u = 'a'; u <= 'z'; ++u)
    if (vis[u - 'a'] == UNVISITED)
      kosaraju(u - 'a', 1);

  vis.assign('z' - 'a' + 1, UNVISITED);
  for (i32 u = 'z'; u >= 'a'; --u)
    if (vis[ts[u - 'a']] == UNVISITED)
      kosaraju(ts[u - 'a'], 2);

  debug(ts);

  set<char> smbls;
  for (auto &name : names)
    for (auto &symb : name)
      smbls.insert(toupper(symb));

  for (i32 i = ts.size() - 1; i >= 0 && !smbls.empty(); --i) {
    char symb = ts[i] + 'A';
    if (smbls.count(symb)) {
      smbls.erase(symb);
      cout << symb;
    }
  }
  cout << '\n';

  return 0;
}
