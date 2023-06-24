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
    vector<i32> s(n);
    for (i32 i = 0; i < s.size(); ++i)
      cin >> s[i];

    for (i32 a = 0; a < n - 5; ++a)
      for (i32 b = a + 1; b < n - 4; ++b)
        for (i32 c = b + 1; c < n - 3; ++c)
          for (i32 d = c + 1; d < n - 2; ++d)
            for (i32 e = d + 1; e < n - 1; ++e)
              for (i32 f = e + 1; f < n; ++f)
                printf("%d %d %d %d %d %d\n", s[a], s[b], s[c], s[d], s[e], s[f]);

    cin >> n;
    if (n)
      printf("\n");
  }

  return 0;
}



