#include <iostream>
#include <vector>

#define int long long
using namespace std;

vector<int> adj[50];
bool visited[50];
vector<int> component;
void dfs (int s) {
	if (!visited[s]) {
		visited[s] = true;
		component.push_back(s);
		for (auto& u : adj[s]) {
			dfs(u);
		}
	}
}

int32_t main () {
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	bool res = true;
	int cnt = 0;
	vector<int> trio;
	vector<int> duo;
	vector<int> solo;
	for (int i = 1; i <= n; ++i) {
		dfs(i);
		if (!component.empty()) {
			if (component.size() == 3)
				for (auto e : component)
					trio.push_back(e);

			if (component.size() == 2)
				for (auto e : component)
					duo.push_back(e);

			if (component.size() == 1)
				for (auto e : component)
					solo.push_back(e);

			if (component.size() > 3) {
				res = false; break;
			}
			component.clear();
		}
	}

	if (duo.size() > 0 && duo.size() / 2 > solo.size()) res = false;
	
	if (res) {
		for (int i = 0; i < trio.size(); ++i) {
			cout << trio[i] << ' ';
			if ((i + 1) % 3 == 0) cout << endl;
		}
		int cnt = 0;
		for (int i = 0; i < duo.size(); ++i) {
			cout << duo[i] << ' ';
			if ((i + 1) % 2 == 0) cout << solo[cnt++] << endl;
		}
		int cnt2 = 0;
		if (cnt != solo.size())
			for (int j = cnt; j < solo.size(); ++j) {
				cout << solo[j] << ' '; ++cnt2;
				if (cnt2 % 3 == 0) cout << endl;
			}
	} else {
		cout << -1 << endl;
	}
}
