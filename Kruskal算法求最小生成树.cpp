/*
给定一个n个点m条边的无向图，图中可能存在重边和自环，边权可能为负数。

求最小生成树的树边权重之和，如果最小生成树不存在则输出impossible。

给定一张边带权的无向图G=(V, E)，其中V表示图中点的集合，E表示图中边的集合，n = |V|，m = |E|。

由V中的全部n个顶点和E中n - 1条边构成的无向连通子图被称为G的一棵生成树，其中边的权值之和最小的生成树被称为无向图G的最小生成树。

数据范围

1≤n≤10^51≤m≤2*10^5

图中涉及边的边权的绝对值均不超过1000


输入

第一行包含两个整数n和m。

接下来m行，每行包含三个整数u、v、w，表示点u和点v之间存在一条权值为w的边。


输出

共一行，若存在最小生成树，则输出一个整数，表示最小生成树的树边权重之和，如果最小生成树不存在则输出impossible。


输入样例 1

4 5
1 2 1
1 3 2
1 4 3
2 3 2
3 4 4
输出样例 1

6
*/

//将所有边按照权重从小到大排序，枚举每条边
//if a,b不连通，将a,b加入集合
//使用并查集查询两个节点是否属于同一集合，合并两个节点
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10, M = 2e5 + 10, INF = 0x3f3f3f3f;
int n, m;
int p[N];

struct Edge {
	int a, b, w;
	bool operator<(const Edge& e)const {
		return w < e.w;
	}
}es[M];

int find(int x) {
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}

int kruskal() {
	int cnt = 0, res = 0;
	sort(es, es + m);
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 0; i < m; i++) {
		int a = es[i].a, b = es[i].b, w = es[i].w;
		a = find(a); b = find(b);
		if (a != b) {
			p[a] = b;
			res += w;
			cnt++;
		}
	}

	if (cnt < n - 1) return INF;
	else return res;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		es[i] = { a,b,w };
	}

	int t = kruskal();
	if (t == INF) {
		cout << "impossible" << endl;
	}
	else {
		cout << t << endl;
	}
	return 0;
}