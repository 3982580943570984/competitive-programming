#include <bits/stdc++.h>

using namespace std;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{}; cin >> t;
  for (; t > 0; --t) {
    int n{}; cin >> n;
    vector<int64_t> a; a.resize(n);
    for (auto& x : a) cin >> x;

    int64_t c{a.front()}, d{};
    for (int i{1}; i < n; ++i) {
      int64_t x{a[i]}, y{a[i-1]};
      if (x < 0 && y < 0 || x > 0 && y > 0) c = max(c, x); else d +=c, c = x;
    }

    cout << d + c << '\n';
  }
}