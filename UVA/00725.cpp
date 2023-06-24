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
  while (n != 0) {
    bool have_solution = false;
    for (i32 i = 01234; i <= (98765 / n); ++i) {
      i32 j = i * n;
      i32 tmp, res = (i < 10000);
      
      tmp = i;
      while (tmp) {
        res |= (1 << (tmp % 10));
        tmp /= 10;
      }

      tmp = j;
      while (tmp) {
        res |= (1 << (tmp % 10));
        tmp /= 10;
      }

      if (res == ((1 << 10) - 1)) {
        have_solution = true;
        printf("%05d / %05d = %d\n", j, i, n);
      }
    }

    if (!have_solution)
      printf("There are no solutions for %d.\n", n);

    cin >> n;
    if (n != 0)
      printf("\n");
  }

  return 0;
}


