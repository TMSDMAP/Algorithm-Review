/*
给定一个n个点m条边的有向图，图中可能存在重边和自环，所有边权均为正值。

请你求出1号点到其他点的最短距离，如果无法从1号点走到n号点，则输出-1。


输入

第一行包含整数n和m。1<=n<=500, 1<=m<=100000

接下来m行每行包含三个整数x，y，z，表示存在一条从点x到点y的有向边，边长为z。


输出

输出n个整数，表示1号点到n号点的最短距离。

*/

//使用优先队列

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <functional>
using namespace std;

struct Edge {
	int to;
	int weight;
};

vector<int> dijkstra(vector<vector<Edge>>& graph, int start, int n) {
	vector<int> dist(n, INT_MAX);
	vector<bool> visited(n, false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		if (visited[u]) continue;
		visited[u] = true;
		for (const Edge& edge : graph[u]) {
			int v = edge.to;
			int weight = edge.weight;
			if (!visited[v] && dist[u] + weight < dist[v]) {
				dist[v] = dist[u] + weight;
				pq.push({ dist[v], v });
			}
		}
	}
	return dist;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<Edge>> graph(n);
	for (int i = 0; i < m; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		graph[x - 1].push_back({ y - 1, z }); // 转换为0-indexed
	}
	int start = 0; // 1号点对应的索引是0
	vector<int> distance = dijkstra(graph, start, n);
	for (int i = 0; i < n; ++i) {
		if (distance[i] == INT_MAX) {
			cout << -1 << " ";
		}
		else {
			cout << distance[i] << " ";
		}
	}
	return 0;
}
