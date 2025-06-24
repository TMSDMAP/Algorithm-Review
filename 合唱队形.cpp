/*
N位同学站成一排，音乐老师要请其中的(N−K)位同学出列，使得剩下的K位同学排成合唱队形。

合唱队形是指这样的一种队形：设KK位同学从左到右依次编号为1，2…，K

他们的身高分别为T1，T2，…，TK

则他们的身高满足T1<…<Ti>Ti+1>…>TK(1≤i≤K)。

你的任务是，已知所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。


输入

输入的第一行是一个整数N，表示同学的总数。

第二行有N个整数，用空格分隔，第i个整数Ti是第i位同学的身高(厘米)。

数据范围
2≤N≤100
130≤Ti≤230


输出

输出包括一行，这一行只包含一个整数，就是最少需要几位同学出列。*/
//线性DP，最长上升子序列

//从前往后以每个点结尾的最长上升子序列长度 f[i]
//从后往前以每个点结尾的最长上升子序列长度 g[i]

//f[k] + g[k] - 1 即为以k为峰的合唱队形的长度

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 110;

int n;
int h[N];
int f[N], g[N];  //// f[i]表示以i结尾的最长上升子序列长度

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> h[i];
	}
	for (int i = 1; i <= n; i++)
	{
		f[i] = 1; //  f[i]表示以i结尾的最长上升子序列长度
		for (int j = 1; j < i; j++) 
		{
			if (h[j] < h[i])
				f[i] = max(f[i], f[j] + 1); //  // 如果h[j] < h[i]，则可以将h[i]接在h[j]后面，更新f[i]
		}
	}
	for (int i = n; i >= 1; i--)
	{
		g[i] = 1;  // g[i]表示以i结尾的最长下降子序列长度
		for (int j = n; j > i; j--)
			if (h[j] < h[i]) g[i] = max(g[i], g[j] + 1); // 如果h[j] < h[i]，则可以将h[i]接在h[j]后面，更新g[i]
	}
	int res = 0;
	for (int i = 1; i <= n; i++)
		res = max(res, f[i] + g[i] - 1);  //// f[i] + g[i] - 1 即为以i为峰的合唱队形的长度

	cout << n - res << endl; // 最少需要出列的人数
	return 0;
}

