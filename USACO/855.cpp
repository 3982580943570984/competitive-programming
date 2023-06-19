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

i32 main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin.exceptions(cin.failbit);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  freopen("mixmilk.in", "r", stdin);
  freopen("mixmilk.out", "w", stdout);
#endif

  vector<i32> c(3), m(3);
  for (i32 i = 0; i < 3; ++i)
    cin >> c[i] >> m[i];

  debug(m);
  for (i32 i = 0; i < 100; ++i) {
    i32 temp = min(c[(i + 1) % 3] - m[(i + 1) % 3], m[i % 3]);
    m[(i + 1) % 3] += temp;
    m[i % 3] -= temp;
  }

  for (i32 i = 0; i < 3; ++i)
    cout << m[i] << endl;

  return 0;
}
