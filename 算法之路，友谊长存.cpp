/*
算法之路，友谊长存

小厦在一个方格（m x n）的左上角，要通过方格上的算法之路找到在方格右下角的朋友小门。算法之路要求每次移动时只能向下或者向右移动一步。请问一共有多少条算法之路能够使得小厦走到方格的右下角。


输入

只有一行数据，分别为m和n，方格的长和高， 1<=m,n<=110


输出

x (一共有多少条路径，可以从方格的最左上角走到方格的最右下角)

答案数据保证不会超过int的数据范围


输入样例 1

3 2
输出样例 1

3
输入样例 2

7 3
输出样例 2

28
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;

	vector<vector<int>> dp(m, vector<int>(n, 0));

	for (int i = 0; i < m; ++i)
		dp[i][0] = 1;
	for (int j = 0; j < n; ++j)
		dp[0][j] = 1;
	for (int i = 1; i < m; ++i) {
		for (int j = 1; j < n; ++j)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	cout << dp[m - 1][n - 1] << endl;
	return 0;
}