/*
厦门大学依山傍水，一共有情人谷、芙蓉隧道、芙蓉湖…等N个可游玩的景点，并且两两之间都有一条通路。

由于访客数量太多，游玩途中常常出现拥堵，所以在节假日期间每段路限制游客只能通行一次。

假期你的朋友来厦大游玩，你要如何规划路线，帮他以最短路线访问所有景点呢？

要求从第一个景点出发，假定从第n-1个点可以离开厦大，所有的点不能重复进入。



出题者：邱梦薇同学

感谢栾英石，李岩铭同学纠错


输入

第一行是一个整数n(1<=n<=8),表示景点的个数，景点编号从0开始。

接下来是一个n*n的对称矩阵,元素dis[i,j]表示景点i与景点j之间道路的长度(1<=dis[i,j]<=10000,dis[i,i]=0,dis[i,j]=dis[j,i])


输出

输出最短路线的长度


输入样例 1

5
0 2 4 5 1
2 0 6 5 3
4 6 0 8 3
5 5 8 0 5
1 3 3 5 0
输出样例 1

18
提示

n很小,可以考虑回溯或分支限界，当然也可以动态规划
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int g[10][10];
int n;
bool vis[10];
int ans = 0x7f7f7f7f;

void dfs(int x, int cnt, int sum) {
	if (sum >= ans) return;
	if (x == n - 1) {
		if (cnt == n) {
			ans = min(ans, sum);
		}
		return;
	}
	if (cnt == n) return;

	for (int i = 0; i < n; i++) {
		if (!vis[i] && g[x][i] > 0) {
			vis[i] = true;
			dfs(i, cnt + 1, sum + g[x][i]);
			vis[i] = false;
		}
	}
}

int main()
{
	cin >> n;
	for(int i = 0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			cin >> g[i][j];
		}
	vis[0] = true; // 从第一个景点出发
	dfs(0, 1, 0); // 从第0个景点出发，已访问1个景点，当前路径长度为0
	cout << ans << endl; // 输出最短路径长度
	return 0;
}