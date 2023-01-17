#include <ios>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define int long long
using namespace std;

vector<int> adj[1001];
bool visited[1001];
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
	int k, n, m; cin >> k >> n >> m;
	vector<vector<string>> tap(k, vector<string>(n));
	for (int i = 0; i < k; ++i)
		for (int j = 0; j < n; ++j)
			cin >> tap[i][j];

	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int l = 0; l < m; ++l) {
				if (tap[i][j][l] == '.') {
					if (l > 0) {
						if (tap[i][j][l] == tap[i][j][l-1]) {
							adj[i*n*m + j*m + l].push_back(i*n*m + j*m + l - 1);
							adj[i*n*m + j*m + l - 1].push_back(i*n*m + j*m + l);
						}
					}

					if (l < m - 1) {
						if (tap[i][j][l] == tap[i][j][l+1]) {
							adj[i*n*m + j*m + l].push_back(i*n*m + j*m + l + 1);
							adj[i*n*m + j*m + l + 1].push_back(i*n*m + j*m + l);
						}
					}

					if (j > 0) {
						if (tap[i][j][l] == tap[i][j-1][l]) {
							adj[i*n*m + j*m + l].push_back(i*n*m + (j-1)*m + l);
							adj[i*n*m + (j-1)*m + l].push_back(i*n*m + j*m + l);
						}
					}

					if (j < n - 1) {
						if (tap[i][j][l] == tap[i][j+1][l]) {
							adj[i*n*m + j*m + l].push_back(i*n*m + (j+1)*m + l);
							adj[i*n*m + (j+1)*m + l].push_back(i*n*m + j*m + l);
						}
					}

					if (i > 0) {
						if (tap[i][j][l] == tap[i-1][j][l]) {
							adj[i*n*m + j*m + l].push_back((i-1)*n*m + j*m + l);
							adj[(i-1)*n*m + j*m + l].push_back(i*n*m + j*m + l);
						}
					}

					if (i < k - 1) {
						if (tap[i][j][l] == tap[i+1][j][l]) {
							adj[i*n*m + j*m + l].push_back((i+1)*n*m + j*m + l);
							adj[(i+1)*n*m + j*m + l].push_back(i*n*m + j*m + l);
						}
					}
				}
			}
		}
	}
	int x, y; cin >> x >> y; --x; --y;
	dfs(x*m + y);
	cout << component.size() << endl;
}
