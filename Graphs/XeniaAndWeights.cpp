#include <algorithm>
#include <iostream>
#include <stdint.h>
#include <vector>

#define int long long
using namespace std;

// consecutive weights must be different
// every step scalepan must outweight the other one

vector<int> adj[11];
bool res = false;
vector<int> elem;
int m;

bool dfs (int s, int p, int d = 0) {
	if (s != 0 && p != 0) {
		if (d > m) return false;
		elem.push_back(p);
		if (d == m) return true;
	}
	for (auto& e : adj[p]) {
		if (e > s && e != p) {
			if (dfs(e - s, e, d + 1))
				return true;
			else
				elem.pop_back();
		}
	}
	return false;
}

int32_t main () {
	string s; cin >> s; cin >> m;
	vector<int> w;
	for (int i = 0; i < s.size(); ++i)
		if (s[i] == '1')
			w.push_back(i + 1);

	for (int i = 0; i < w.size(); ++i) {
		adj[0].push_back(w[i]);
		for (int j = 0; j < w.size(); ++j)
			if (w[j] != w[i])
				adj[w[i]].push_back(w[j]);
	}

	for (int i = 0; i < w.size(); ++i) {
		res = dfs(0, 0);
		if (res) break;
	}

	cout << (res ? "YES\n" : "NO\n");
	if (res) {
		for (auto e : elem) cout << e << ' ';
	}
}
