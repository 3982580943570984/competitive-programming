#include <bits/stdc++.h>

using namespace std;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n{}; cin >> n;

  vector<int> a{}; a.resize(n);
  for (auto& x : a) cin >> x;

  int b{1}, c{1};
  for (int i{1}; i < n; ++i) {
    if (a[i] >= a[i-1]) {
      ++b;
    } else {
      c = max(c, b);
      b = 1;
    }
  }

  cout << max(c, b) << '\n';
}