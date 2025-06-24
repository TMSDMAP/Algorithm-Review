/*
农民多多被选为他们镇的镇长！多多决定在镇上建立起互联网，并连接到所有的农场。

多多给他的农场安排了一条高速的网络线路，他想把这条线路共享给其他农场。

为了节省成本，多多想铺设最短的光纤去连接所有的农场。

多多得到了一份各农场之间连接费用的列表，现在需要找出能连接所有农场并所用光纤最短的方案。


输入

第一行：农场的个数，N（3≤N≤100）。

接下来的N行：一个N×N的矩阵,表示每个农场之间的距离dij。用空格分隔。（dij<=100000）


输出

能连接所有农场的所用光纤的最小长度


输入样例 1

4
0 4 9 21
4 0 8 17
9 8 0 16
21 17 16 0
输出样例 1

28*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int n;
vector<vector<int>> graph;

int prim()
{
	vector<bool> visited(n, false);
	vector<int> minCost(n, INT_MAX);
	minCost[0] = 0; // 从第一个农场开始
	int totalCost = 0;
	for (int i = 0; i < n; i++)
	{
		int u = -1;
		for (int j = 0; j < n; j++)
		{
			if (!visited[j] && (u == -1 || minCost[j] < minCost[u]))
				u = j;
		}
		if (u == -1) break; // 所有农场都已访问或无法连接
		visited[u] = true; // 标记当前农场为已访问
		totalCost += minCost[u]; // 累加当前农场的最小成本
		for (int v = 0; v < n; v++)
		{
			if (!visited[v] && graph[u][v] < minCost[v])
			{
				minCost[v] = graph[u][v];
			}
		}
	}
	
	return totalCost;
}

int main()
{
	cin >> n;
	graph.resize(n);
	for(int i = 0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			int x;
			cin >> x;
			graph[i].push_back(x);
		}
	int result = prim();
	cout << result << endl;
	return 0;
}