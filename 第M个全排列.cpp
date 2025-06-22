/*
"又错了！"铁柱懊恼地抓了抓头发，面前的草稿纸上密密麻麻写满了数字排列。自从学会了递归算法，他就对全排列产生了浓厚的兴趣。可是现在，他遇到了一个棘手的问题：如何快速找到某个排列之后第m个排列（排列按照字典序升序）？你能帮帮他吗？

出题人：刘政柱同学


输入

一共三行

第一行是一个整数N，代表全排列的位数，（1≤N≤10000）

第二行是一个整数M，代表某一个排列之后的第M个排列（1≤M≤100）。

第三行是一个排列，由1到N这N个数组成。


输出

N个整数，代表输入的排列之后的第M个排列。*/

//类似NOIP 火星人

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, r;
int m;
int q0[10010];
bool flag[10];

int main()
{
	cin >> n >> m;
	r = n;
	int s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		q0[i] = s;
	}
	while (m--) next_permutation(q0, q0 + n);
	for (int i = 0; i < n; i++)
	{
		cout << q0[i];
		if (i != n - 1) cout << " ";
	}
	return 0;
}