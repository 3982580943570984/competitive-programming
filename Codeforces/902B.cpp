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
  #endif

  i32 n; cin >> n;
  
  vector<i32> p(n);
  p[0] = 0;
  for (i32 i = 1; i < p.size(); ++i) {
    cin >> p[i];
    --p[i];
  }

  vector<i32> clrs(n);
  for (i32 i = 0; i < clrs.size(); ++i)
    cin >> clrs[i];

  i32 res = 0;
  for (i32 i = 1; i < n; ++i)
    if (clrs[i] != clrs[p[i]])
      ++res;

  cout << res + 1 << endl;

  return 0;
}
