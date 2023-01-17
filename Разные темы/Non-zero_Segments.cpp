#include <ios>
#include <iostream>
#include <stdint.h>
#include <set>

#define int long long
using namespace std;

int32_t main () {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n; cin >> n;
  set<int> pref {0};
  int p = 0LL, res = 0LL;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x; p += x;
    if (pref.contains(p)) {
      ++res; p = x; pref.clear(); pref.insert(0);
    }
    pref.insert(p);
  }
  cout << res << endl;
}
