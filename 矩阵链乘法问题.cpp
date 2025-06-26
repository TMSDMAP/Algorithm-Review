/*
给定一个有 n 个矩阵的矩阵链 (Matrix Chain) 
输入共 n+1 行
第一行输入矩阵的总个数 n [2,1000]
后 n 行分别输入矩阵的维数 [1,100]输出
最后一行输出少乘法次数*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> p(n + 1);
	for (int i = 0; i < n; ++i) {
		int row, col;
		cin >> row >> col;
		p[i] = row;
		if (i == n - 1) {
			p[i + 1] = col; // 最后一个矩阵的列数
		}
	}
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

	for (int l = 2; l <= n; l++) {
		for (int i = 1; i <= n - l + 1; i++)
		{
			int j = i + l - 1;
			dp[i][j] = INT_MAX;  // 初始化为最大值
			for (int k = i; k < j; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j]);  // 计算最小乘法次数
			}
		}
	}
	cout << dp[1][n] << endl; // 输出最少乘法次数
	return 0;
}

