/*
自从疫情开始流行，口罩便成了防疫至关重要的物资，然而仅有工厂的生产力远远不够，更需要有效的流通手段来使得生产的口罩尽可能地分配到最急需的地方。

为此我们的规划了一条从生产地到目标地区的运输路线方案，我们已知每一段路线的最大运输量以及该运输方案的整体规划。其中每段路线是单向流通的，可能出现环形路段。

现在我们需要根据这些信息，求得该运输方案从口罩生产地到目标的最大运输量。


输入

第1行:两个用空格分开的整数M,N(0<M≤200,0<N≤200)。M是方案中的路段数量,N是路线交汇点的数量。其中点1是生产地,点N是目的地。

第2行到第M+1行:每行有三个整数Si,Ei,Ci。 其中Si​和Ei(1≤Si,Ei≤N)指明该路段的两个端点,口罩从Si​单向运往Ei​。Ci(0<Ci≤100000)是这段路线的最大运输量.


输出

输出一个整数，即该运输方案的最大运输量。


输入样例 1

5 4
1 2 40
1 4 20
2 4 20
2 3 30
3 4 10
输出样例 1

50*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 205;
const int INF = 1e9;

int capacity[MAXN][MAXN]; // 容量矩阵
vector<int> adj[MAXN]; // 邻接表
int parent[MAXN]; // 用于存储增广路径

bool bfs(int source, int sink)
{
	memset(parent, -1, sizeof(parent));
	queue<int> q;
	q.push(source);
	parent[source] = -2;

	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int v : adj[u])
		{
			if (parent[v] == -1 && capacity[u][v] > 0)
			{
				parent[v] = u;
				if (v == sink) return true;
				q.push(v);
			}
		}
	}
	return false;
}

int EK(int source, int sink)
{
	int maxFlow = 0;
	while (bfs(source, sink))
	{
		int flow = INF;
		for (int v = sink; v != source; v = parent[v])
		{
			int u = parent[v];
			flow = min(flow, capacity[u][v]);
		}
		for (int v = sink; v != source; v = parent[v])
		{
			int u = parent[v];
			capacity[u][v] -= flow;
			capacity[v][u] += flow;
		}
		maxFlow += flow;
	}
	return maxFlow;
}

int main()
{
	int M, N;
	cin >> M >> N;
	for (int i = 0; i < M; i++)
	{
		int s, e, c;
		cin >> s >> e >> c;
		capacity[s][e] += c; // 注意可能有多条边
		adj[s].push_back(e);
		adj[e].push_back(s); // 添加反向边
	}
	int source = 1;
	int sink = N;
	int maxFlow = EK(source, sink);
	cout << maxFlow << endl;
	return 0;
}