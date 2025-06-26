/*
有N件物品和一个容量是V的背包。每件物品只能使用一次。

第i件物品的体积是vi，价值是wi。

求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
输出最大价值。

数据范围
0<N,V≤1000
0<vi,wi≤100


输入

第一行两个整数，N，V，用空格隔开，分别表示物品数量和背包容积。

接下来有N行，每行两个整数vi,wi，用空格隔开，分别表示第i件物品的体积和价值。


输出

输出一个整数，表示最大价值。*/

#include <iostream>
using namespace std;
const int N = 1010;
int f[N][N];
int v[N], w[N];
int n, m;
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> v[i] >> w[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			
			if (j >= v[i])
				f[i][j] = max(f[i-1][j], f[i - 1][j - v[i]] + w[i]);
			else f[i][j] = f[i - 1][j];
		}
	}
	cout << f[n][m] << endl;
	return 0;
}

//一维数组必须j逆序遍历，否则会污染