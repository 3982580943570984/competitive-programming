#include <bits/stdc++.h>

using namespace std;

int main () {
  int t{}; cin >> t;
  while (t--) {
    int n{}; cin >> n;
    vector<int> a{}; a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    set<int> s{a.cbegin(), a.cend()};
    cout << (s.size() != n ? "YES\n" : "NO\n");
  }
}