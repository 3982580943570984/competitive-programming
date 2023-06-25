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

  i32 a, b; cin >> a >> b;

  vector<i32> s {b};
  while (true) {
    i32 x = s.back();

    if (x < a)
      break;

    if (x == a)
      break;

    if (x % 10 == 1)
      s.push_back(x / 10);
    else if (!(x & 1))
      s.push_back(x / 2);
    else
      break;
  }

  if (s.back() != a) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    cout << s.size() << endl;
    reverse(s.begin(), s.end());
    for (auto u : s)
    cout << u << ' ';
  }


  return 0;
}
