#include <bits/stdc++.h>

using namespace std;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{}; cin >> t;
  while (t--) {
    int n{}; cin >> n;
    vector<int64_t> g{}; g.resize(n);
    for (int i{}; i < n; i++) cin >> g[i];
    sort(g.begin(), g.end());

    if (n % 2 == 0) {
      int64_t s{};
      for (int i{1}; i < n; i += 2) s += g[i];
      cout << s << '\n';
      continue;
    }

    int64_t s1{g.back()};
    for (int i{1}; i < n; i += 2) s1 += g[i];

    int64_t s2{g.front()};
    for (int i{2}; i < n; i += 2) s2 += g[i];

    cout << min(s1, s2) << '\n';
  }
}