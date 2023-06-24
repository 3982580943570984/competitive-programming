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

  i32 c, n, m; 
  cin >> c >> n >> m;
  vector<vector<i64>> dp(51, vector<i64>(c+1));

  for (i32 i = 0; i < n; ++i) {
    i64 number_of_cows;
    cin >> number_of_cows;
    ++dp[0][number_of_cows];
  }

  for (i32 i = 0; i < 50; ++i)
    for (i32 j = 1; j <= c; ++j)
      (j <= (c >> 1)) ? dp[i+1][j << 1] += dp[i][j] : dp[i+1][j] += (dp[i][j] << 1);

  debug(dp);

  for (i32 i = 0; i < m; ++i) {
    i32 day;
    cin >> day;
    cout << accumulate(dp[day].begin(), dp[day].end(), 0LL) << endl;
  }

  return 0;
}

