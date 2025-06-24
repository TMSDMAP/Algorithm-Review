/*
有N种物品和一个容量是V的背包。

第i种物品最多有si件，每件体积是vi，价值是wi。

求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
输出最大价值。

数据范围
0<N,V≤100
0<vi,wi,si≤100


输入

第一行两个整数，N，V，用空格隔开，分别表示物品种数和背包容积。

接下来有N行，每行三个整数vi,wi,si，用空格隔开，分别表示第i种物品的体积、价值和数量。


输出

输出一个整数，表示最大价值。*/

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 110;

int v[N], w[N], f[N][N], cnt[N];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> v[i] >> w[i] >> cnt[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int k = 0; k <= cnt[i] && k * v[i] <= j; k++)
				f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
	cout << f[n][m] << endl;
	return 0;
}


