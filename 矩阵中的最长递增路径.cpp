/*
给定一个 m x n 整数矩阵 matrix ，找出其中最长递增路径的长度。
对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在对角线方向上移动或移动到边界外（即不允许环绕）。
输入
第一行n，m。1<=n,m<=200
接下来是n*m的矩阵
输出
最长递增路径
输入样例 1
3 3
9 9 4
6 6 8
2 1 1
输出样例 1
4
输入样例 2
3 3
3 4 5
3 2 6
2 2 1
输出样例 2
4*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct Node {
	int h;
	int x;
	int y;
};
int R, C;
Node node[40005];
int dp[205][205];
int map[205][205];
int directions[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

bool compare(Node a, Node b) {
	return a.h > b.h;
}

int main()
{
	cin >> R >> C;
	for(int i = 1;i<=R;i++)
		for(int j = 1;j<=C;j++)
			cin >> map[i][j];
	for (int i = 1; i <= R * C; i++)
	{
		node[i].x = (i - 1) / C + 1;
		node[i].y = (i - 1) % C + 1;
		node[i].h = map[node[i].x][node[i].y];
	}   //用一维数组存储二维矩阵的坐标和高度信息
	sort(node + 1, node + 1 + R * C, compare);  //对节点按高度从大到小排序
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			dp[i][j] = 1;
	int m = -1;
	for (int i = R * C; i >= 1; i--) 
	{
		int x = node[i].x;
		int y = node[i].y;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + directions[i][0];
			int ny = y + directions[i][1];
			if (nx >= 1 && nx <= R && ny >= 1 && ny <= C && map[nx][ny] < map[x][y]) {
				dp[x][y] = max(dp[x][y], dp[nx][ny] + 1);
			}
		}   //dp记录最长递增路径长度
		m = max(m, dp[x][y]);
	}
	cout << m << endl;
}