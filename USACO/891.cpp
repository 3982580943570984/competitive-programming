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
  freopen("shell.in", "r", stdin);
  freopen("shell.out", "w", stdout);
#endif

  i32 n;
  cin >> n;
  vector<i32> shells(3);
  for (i32 i = 0; i < 3; ++i)
    shells[i] = i;

  vector<i32> counter(3);
  for (i32 i = 0; i < n; ++i) {
    i32 a, b, g;
    cin >> a >> b >> g;
    --a, --b, --g;

    swap(shells[a], shells[b]);
    counter[shells[g]]++;
  }

  cout << *max_element(counter.begin(), counter.end()) << endl;

  return 0;
}
