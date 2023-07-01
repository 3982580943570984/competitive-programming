#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using namespace std;

template<typename T>
using vec = std::vector<T>;

template<typename Key, typename Hash = std::hash<Key>, typename KeyEqual = std::equal_to<Key>, typename Allocator = std::allocator<Key>>
using uset = std::unordered_set<Key, Hash, KeyEqual, Allocator>;

template<typename Key, typename Compare = std::less<Key>, typename Allocator = std::allocator<Key>>
using mset = std::multiset<Key, Compare, Allocator>;

template<typename Key, typename T, typename Compare = std::less<Key>, typename Allocator = std::allocator<std::pair<const Key, T>>>
using mmap = std::multimap<Key, T, Compare, Allocator>;

template<typename Key, typename Value, typename Hash = std::hash<Key>, typename KeyEqual = std::equal_to<Key>, typename Allocator = std::allocator<std::pair<const Key, Value>>>
using umap = std::unordered_map<Key, Value, Hash, KeyEqual, Allocator>;

using f32 = float;
using f64 = double;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

const i32 N = 200005;
i32 t[4 * N];

void build (i32 v, i32 l, i32 r) {
  if (l == r) { t[v] = l; return; }
  i32 m = (l + r) >> 1;
  build(v << 1, l, m);
  build(v << 1 | 1, m + 1, r);
  t[v] = min(t[v << 1], t[v << 1 | 1]);
}

i32 get (i32 v, i32 l, i32 r, i32 ql, i32 qr) {
  if (ql > r || qr < l) return INT_MAX;
  if (ql <= l && qr >= r) return t[v];
  i32 m = (l + r) >> 1;
  return min(get(v << 1, l, m, ql, qr), get(v << 1 | 1, m + 1, r, ql, qr));
}

void upd (i32 v, i32 l, i32 r, i32 p, i32 val) {
  if (l == r) { t[v] = val; return; }
  i32 m = (l + r) >> 1;
  p <= m
    ? upd(v << 1, l, m, p, val)
    : upd(v << 1 | 1, m + 1, r, p, val);
  t[v] = min(t[v << 1], t[v << 1 | 1]);
}

i32 main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin.exceptions(cin.failbit);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #else
    freopen("exam.in", "r", stdin);
    freopen("exam.out", "w", stdout);
  #endif

  build(1, 1, N);
  i32 k; cin >> k;
  for (i32 i = 0; i < k; ++i) {
    i32 a; cin >> a;
    if (a > 0) {
      i32 r = get(1, 1, N, a, N);
      cout << r << endl;
      upd(1, 1, N, r, INT_MAX);
    } else {
      upd(1, 1, N, -a, -a);
    }
  }

  return 0;
}
