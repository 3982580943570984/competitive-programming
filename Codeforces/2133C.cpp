#include <bits/stdc++.h>

using namespace std;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{}; cin >> t;
  while (t--) {
    int n{}; cin >> n;
    vector<int> c{}; c.resize(n);
    unordered_map<int, vector<int>> d{};
    int m{};
    for (int i{1}; i <= n; ++i) {
      cout << '?' << ' ' << i << ' ' << n << ' ';
      for (int j{1}; j <= n; ++j) {
        cout << j;
        if (j != n) cout << ' ';
      }
      cout << endl;
      cout.flush();
      cin >> c[i - 1];
      d[c[i - 1]].push_back(i);
      m = max(m, c[i - 1]);
    }
    vector<int> e{}; e.reserve(m - 1); e.push_back(d[m].front());
    for (int i{m - 1}; i > 0; --i) {
      for (auto& f : d[i]) {
        cout << '?' << ' ' << e.back() << ' ' << 2 << ' ' << e.back() << ' ' << f;
        cout << endl;
        cout.flush();
        int x{}; cin >> x;
        if (x == 2) { e.push_back(f); break; }
      }
    }
    cout << '!' << ' ' << e.size() << ' ';
    for (int i{}; i < e.size(); ++i) {
      cout << e[i];
      if (i != e.size() - 1) cout << ' ';
    }
    cout << endl;
    cout.flush();
  }
}