/*
有2N个球，每个球的颜色用1到N之间的整数表示，每种颜色的球正好有2个。

这些球被放入M个筒中，第i个筒中有ki个球，第j个球的颜色为ai,j。

目标是通过以下操作将M个筒中的所有球都清空：

选择两个不同的非空筒，从每个筒的最上面取出一个球并丢弃。取出的两个球必须是同一种颜色。你需要判断是否可以通过这些操作清空所有的筒。

请输出一个结果，如果能够清空所有筒，输出"Yes"，否则输出"No"。

出题人：高鑫辉同学


输入

第一行包含两个整数N和M，N表示球的颜色种类数，M表示筒的数量。

接下来的M行分别描述每个筒中的球：每行首先给出一个整数ki，表示第i个筒中的球的数量。接下来是ki个整数ai,1, ai,2, ..., ai,k，表示第i个筒中的球的颜色编号。


输出

如果能够通过操作清空所有筒，输出Yes，否则输出No。


输入样例 1

2 2
2
1 2
2
1 2
输出样例 1

Yes
提示

第一步，选择第一个筒和第二个筒，从每个筒的最上面取出一个球并丢弃。丢弃的两个球颜色都是1，符合条件，因此这个操作是有效的。

第二步，选择第一个筒和第二个筒，从每个筒的最上面取出一个球并丢弃。丢弃的两个球颜色都是2，符合条件，因此这个操作是有效的。所以能够通过操作清空所有筒，输出Yes。

数据范围：

1≤N≤2×10^5

2≤M≤2×10^5

1≤ki(1≤i≤M)
*/
//拓扑排序

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

bool canEmptyTubes() {
	int n, m;
	cin >> n >> m;
	map<int, vector<pair<int, int>>> colorPositions;
	vector<vector<int>> tubes(m);
	//记录每种颜色的球在筒中的位置
	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> k;
		tubes[i].resize(k);

		for (int j = 0; j < k; j++) {
			cin >> tubes[i][j];
			colorPositions[tubes[i][j]].push_back({ i, j });
		}
	} //检查每种颜色的球是否在两个不同的筒中
	for (int color = 1; color <= n; color++) {
		if (colorPositions[color].size() != 2) {
			return false;
		}
		if (colorPositions[color][0].first == colorPositions[color][1].first) {
			return false; // 同一种颜色的球在同一个筒中
		}
	}
	vector<vector<int>> graph(n + 1);
	vector<int> inDegree(n + 1, 0);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < tubes[i].size() - 1; j++) {
			int bottomColor = tubes[i][j];
			int topColor = tubes[i][j + 1];
			graph[topColor].push_back(bottomColor);
			inDegree[bottomColor]++;
		}
	}
	queue<int> q;
	int visited = 0;
	 //建图，进行拓扑排序
	for (int color = 1; color <= n; color++) {
		if (inDegree[color] == 0) {
			q.push(color);
		}
	}
	while (!q.empty())
	{
		int current = q.front();
		q.pop();
		visited++;
		for (int neighbor : graph[current]) {
			inDegree[neighbor]--;
			if (inDegree[neighbor] == 0) {
				q.push(neighbor);
			}
		}
	}

	return visited == n;
}

int main()
{
	if (canEmptyTubes()) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}