#include <iostream>
#include <vector>
#include <queue>
#include <stdint.h>

std::vector<int> adj[10]; // массив, хранящий вершины и их связи
bool visited[10];

// обход графа в глубину O(n+m)
// Проверка связности компонентов (связанные части графа)
void dfs(int search) {
	if(visited[search]) return; // Проверка на зацикливание
	visited[search] = true;
	for(auto v : adj[search]) dfs(v);
}

// обход графа в ширину O(n+m)
std::queue<int> q; // Очередь для вершин
int distance[10]; // Расстояние между вершинами
void bfs() {
	while(!q.empty()) {
		int search = q.front(); q.pop();
		for(auto v : adj[search]) {
			if(visited[v]) continue;
			visited[v] = true;
			distance[v] = distance[search] + 1;
			q.push(v);
		}
	}
}

int32_t main() {
	return 0;
}
