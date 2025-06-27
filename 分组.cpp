/*
有n个人，给出每个人的身高和体重（不存在两个人的身高和体重都相同），现在要从中选出三个人组成一组，这三个人要至少满足如下条件之一：

1、三个人的身高互不相同

2、三个人的体重互不相同

问最多能找出多少个不同的组。

出题人：张俊圣同学


输入

第一行一个整数n（3<=n<=2e5），

下面n行每行两个整数a_i和b_i，分别为第i个人的身高和体重（1<=a_i,b_i<=n）。


输出

一行，一个整数，代表不同组的个数。


输入样例 1

5
1 1
1 2
1 3
2 2
2 3
输出样例 1

4
提示

对于给出的示例，4组分别为：

第1组：i_1，i_2，i_3

第2组：i_1，i_2，i_5

第3组：i_1，i_3，i_4

第4组：i_1，i_4，i_5
*/

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// 这道题目可以通过计算总的三人组合数，然后减去不满足条件的组合数来解决。
// 首先计算所有三人组合的总数，然后统计那些身高和体重都相同的组合，最后用总数减去这些不满足条件的组合数。
// 这样可以有效地避免暴力枚举的复杂度。
//数学题
int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	vector<long long> h(n + 1, 0);
	vector<long long> w(n + 1, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first >> v[i].second;
		h[v[i].first]++;
		w[v[i].second]++;
	}
	long long nn = n;
	long long total = nn * (nn - 1) * (nn - 2) / 6; // 三人组合总数

	long long inv = 0;
	for (int i = 0; i < n; i++) {
		long long h_count = h[v[i].first];
		long long w_count = w[v[i].second];
		inv += (h_count - 1) * (w_count - 1); // 减去身高和体重都相同的组合
	}

	long long result = total - inv; // 减去不满足条件的组合
	cout << result << endl; // 输出结果
	return 0;

}