/*
多年过去，曾经在算法实验课上抓耳挠腮写代码的你成为了厦门大学信息学院的一名老师，这天，许久没有点名的你为了应对不知何时会出现的出勤检查，你决定在这堂课进行签到点名。

然而，经过多年的迭代，签到码并不再是当年那么简单的四位数字，而是一个由小写英文字母组成的字符串S（1<=|S|<=100），同时，为了应对聪明的学生的抓包，签到码不再直接生成在系统中，而是通过N（1<=N<=100）个不同的包组成，每个包里有A _i(1<=A_i<=100)个字符串（S_{i,1},S_{i,2}…S_{i,A_i}）。

一开始，你有一个空的字符串并位于时刻1，从1到N时刻，系统会从第1个包遍历到第N个包，经过当前包时系统可以选择以下两个操作之一：

1.花费一个系统资源，从当前包的A_i个字符串中选择任一个字符串拼接到你的字符串后。

2.什么事都不做。

作为一个勤俭持家的老师，你想知道脑海里浮现的这个签到码S花费的最少系统资源。注意：系统里的包可能无法生成你想的签到码，这时输出-1。

输入格式如下：

S

N

A_1 S_{1,1} S_{1,2}…S_{1,A_1}

…

A_i S_{i,1} S_{i,2}…S_{i,A_i}

…

A_N S_{N,1} S_{N,2}…S_{N,A_N}


输出

输出生成S需要花费的最少系统资源，或者-1表示无法生成该签到码。


输入样例 1

abcde
3
3 ab abc abcd
4 f c cd bcde
2 e de
输出样例 1

2
输入样例 2

abcde
3
2 ab abc
3 f c bcde
1 e
输出样例 2

-1
输入样例 3

aaabbbbcccc
6
2 aa aaa
2 dd ddd
2 ab aabb
4 bbaa bbbc bbb bbcc
2 cc bcc
3 ccc cccc ccccc
输出样例 3

4
提示

数据范围：

对应100%的数据:1<=|S|<=100,1<=N<=100,1<=A_i<=100
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int Inf = 0x3f3f3f3f;

string s;
int N;
vector<vector<string>> v;
int dp[105][105];

int main()
{
	cin >> s;
	cin >> N;
	v.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		int k;
		cin >> k;
		v[i].resize(k);
		for (int j = 0; j < k; j++)
		{
			cin >> v[i][j];
		}
	}

	for (int i = 0; i <= N; ++i)
	{
		for (int j = 0; j <= s.size(); ++j)
		{
			dp[i][j] = Inf;
		}
	}
	dp[0][0] = 0;
	//想出来dp数组要怎么构建是关键，这里是使用前 i 个数据包，生成目标签到码的前 j 个字符所需的最少系统资源
	int len = s.size();

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 0; j <= len; ++j)
		{
			dp[i][j] = min(dp[i][j], dp[i - 1][j]);
		}  //不使用当前数据包
		for (int j = 0; j <= len; ++j)
		{  //使用当前数据包
			for (int k = 0; k < v[i].size(); k++)
			{ //遍历每个子串
				if (j + v[i][k].size() > len) continue;
				if (v[i][k] == s.substr(j, v[i][k].size()))
				{
					dp[i][j + v[i][k].size()] = min(dp[i][j + v[i][k].size()], dp[i - 1][j] + 1);
				}  //大由小来
		}
	}
		if (dp[N][len] == Inf)
			cout << -1 << endl;
		else
			cout << dp[N][len] << endl;
		return 0;
}