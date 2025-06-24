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

//使用DFS+记忆化搜索
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int n, m;
vector<vector<int>> matrix;
vector<vector<int>> memo; 

int dfs(int x, int y)
{
	if (memo[x][y] != 0) return memo[x][y];
	int max_len = 1;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny<m && matrix[nx][ny]>matrix[x][y])
			max_len = max(max_len, dfs(nx, ny) + 1);
	}
	memo[x][y] = max_len;
	return max_len;
}

int longestIncreasingPath() {
	if (n == 0) return 0;
	memo = vector<vector<int>>(n, vector<int>(m, 0));
	int result = 0;
	for(int i =0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			result = max(result, dfs(i, j));
		}
	return result;
}

int main()
{
	cin >> n >> m;
	matrix.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> matrix[i][j];
	cout << longestIncreasingPath() << endl;
	return 0;
}