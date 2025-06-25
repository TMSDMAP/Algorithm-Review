/*
小H将N(1<=N<=100)个石子摆成一圈.现在要将石子有次序地合并成一堆.

规定每次只能选相邻的两堆合并成新的一堆,并将新的一堆的石子数记为该次合并的得分.

请你帮助小H计算这个游戏的最小得分和最大得分.


输入

数据的第1行是正整数N(1<=N<=100),表示有N堆石子.

第2行有N个整数.第i个整数ai(1<=ai<=10)​表示第i堆石子的个数.


输出

输出共2行,第1行为最小得分,第2行为最大得分.


输入样例 1

4
4 5 9 4
输出样例 1

43
54*/

#include <iostream>
#include <cstring>
using namespace std;

const int N = 210, M = N << 1, INF = 0x3f3f3f3f;

int n;
int w[M], s[M];
int f[M][M], g[M][M];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> w[i];
		w[i + n] = w[i];
	}
	//我们可以把链延长两倍，变成 2n个堆，再用区间dp 
	for (int i = 1; i <= n << 1; ++i) s[i] = s[i - 1] + w[i];

	memset(f, -0x3f, sizeof(f));
	memset(g, 0x3f, sizeof(g)); 
	for (int len = 1; len <= n; ++len)
	{
		for (int l = 1; l <= n << 1; ++l)
		{
			int r = l + len - 1;
			if (r > n << 1) break;
			if (len == 1) f[l][l] = g[l][l] = 0;
			else
			{
				for (int k = l; k + 1 <= r; ++k)
				{
					f[l][r] = max(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]); 
					g[l][r] = min(g[l][r], g[l][k] + g[k + 1][r] + s[r] - s[l - 1]);
				}
			}
		}
	}
	int minv = INF, maxv = -INF;
	for (int l = 1; l <= n; ++l)
	{
		minv = min(minv, g[l][l + n - 1]);
		maxv = max(maxv, f[l][l + n - 1]);
	}
	cout << minv << endl;
	cout << maxv << endl;
	return 0;
}