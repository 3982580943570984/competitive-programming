#include <ios>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define int long long
using namespace std;

vector<int> adj[100001];
bool visited[100001];
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
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		int p; cin >> p;
		adj[i].push_back(p);
	}
	vector<vector<int>> components;
	for (int i = 1; i <= n; ++i) {
		dfs(i);
		if (!component.empty()) {
			components.push_back(component);
			component.clear();
		}
	}
	sort(components.begin(), components.end(), [](auto l, auto r) { return l.size() > r.size(); });
	if (components.size() >= 2) {
		auto f = components[0].size();
		auto s = components[1].size();
		auto t = 0;
		for (auto it = components.begin() + 2; it != components.end(); ++it)
			t += it->size() * it->size();
		cout << (f + s) * (f + s) + t << endl;
	} else {
		auto f = components[0].size();
		cout << f * f << endl;
	}
	/*
	for (auto co : components) {
		for (auto c : co)
			cout << c << ' ';
		cout << "-> " << co.size() << endl;
	}
	*/
}
