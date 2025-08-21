#include <bits/stdc++.h>

using namespace std;
using namespace ranges;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n{}, k{};
  cin >> n >> k;

  vector<int> a{}; a.resize(n);
  for (auto& x : a) cin >> x;

  int b{fold_left(a.cbegin(), a.cbegin() + k, 0, plus{})}, c{}, d{};
  c = b;
  for (int i{1}; i < n - k + 1; ++i) {
    b += a[i + k - 1] - a[i - 1];
    if (b < c) c = b, d = i;
  }

  cout << d + 1 << "\n";
}