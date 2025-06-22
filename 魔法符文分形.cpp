/*
古老的魔法书中记载着一种生成无限符文序列的秘术。给定初始符文串s，每次施法时会将当前符文串s与其“镜像分身”拼接。通过反复施法，符文序列的长度将指数增长。现在大法师需要你破解这个魔法规律，确定在无限符文序列中第N个位置的字符。

注：镜像分身是将原符文串的最后一个字符移到最前形成的变形。例如，符文串"FATE"的镜像分身是"EFAT"。

出题人：梁辰景同学。


输入

输入一行，包含一个由大写字母组成的字符串s（1<=|s|<=30）和一个整数N（1<=N<=1e18）


输出

输出无限符文序列的第N个字符（首个字符位置为N=1）


输入样例 1

RUNE 11
输出样例 1

U
提示

对于给出的示例，RUNE，前两次施法过程为：

首次施法：RUNE + ERUN → RUNEERUN（长度8）

二次施法：RUNEERUN+NRUNEERU→ RUNEERUNNRUNEERU（长度16）

所以这个无限符文序列的第11个字符为U

数据范围：

对应20%的数据:1<=|s|<=30,1<=N<=1000

对应60%的数据:1<=|s|<=30,1<=N<=1e8

对应100%的数据:1<=|s|<=30,1<=N<=1e18*/

//与洛谷P3612 [USACO17JAN] Secret Cow Code S相似
//先正常复制，如果是非末尾字符，那么就n-1-t/2,否则就直接n-1或者t/2;t为字符串长度
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

long long N;
char s[35];

void find(char* s, long long N)
{
	if (N <= strlen(s))
	{
		cout << s[N - 1] << endl; // 输出第N个字符
		return;
	}
	long long len = strlen(s);
	while (len < N)
	{
		len * 2;
	}//找到包含N的最小序列

	while (len > strlen(s))
	{
		len /= 2;
		if (N <= len) continue;//如果N在前半部分，直接继续
		if (N == len + 1) N = len;
		else N = (N - 1 - len) % len;  //取余可以不加？
	}
	if (N <= strlen(s))
	{
		cout << s[N - 1] << endl; // 输出第N个字符
		return;
	}
}

int main()
{
	cin >> s >> N;
	find(s, N);
	return 0;
}