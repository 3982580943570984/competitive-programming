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

const i32 N = 100005;
i32 n;
i64 t[N << 1];

void build () {
  for (i32 i = n - 1; i > 0; --i)
    t[i] = t[i << 1] + t[i << 1 | 1];
}

void update(int p, int v) {
  for (t[p += n] = v; p > 1; p >>= 1)
    t[p >> 1] = t[p] + t[p ^ 1];
}

i64 query (i32 l, i32 r) {
  i64 s = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) s += t[l++];
    if (r & 1) s += t[--r];
  }
  return s;
}

i32 main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin.exceptions(cin.failbit);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #else
    freopen("sum.in", "r", stdin);
    freopen("sum.out", "w", stdout);
  #endif

  cin >> n;
  build();

  i32 k; cin >> k;

  for (i32 i = 0; i < k; ++i) {
    char q; cin >> q;
    if (q == 'A') {
      i32 p, v; cin >> p >> v;
      update(p, v);
    }
    else {
      i32 l, r; cin >> l >> r;
      cout << query(l, r + 1) << endl;
    }
  }

  return 0;
}
