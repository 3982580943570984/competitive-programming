#include <algorithm>
#include <cstddef>
#include <ios>
#include <vector>
#include <iostream>
#include <stdint.h>

#define int long long
using namespace std;

bool res = false;
vector<int> rv;
void dfs (int s, int e, vector<int> r) {
	if (s < e || s < 0) return;
	if (s == e) { res = true; rv = r; return; }
	if (!(s & 1)) { r.push_back(s >> 1); dfs (s >> 1, e ,r); }
	if (s % 10 == 1) { r.push_back(s / 10); dfs (s / 10, e, r); }
}

int32_t main () {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int a, b; cin >> a >> b;
	dfs (b, a, vector<int>{b});
	if (!res) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		cout << rv.size() << '\n';
		reverse(rv.begin(), rv.end());
		for (auto e : rv) cout << e << ' ';
		cout << '\n';
	}
}
