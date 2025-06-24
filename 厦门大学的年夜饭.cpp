/*
寒假留校，厦门大学向留校师生发放年夜饭的免费就餐券，只能用一个餐盘凭借就餐券打不同的菜肴，假设每一道菜肴都有相应的价格，装在不同体积的菜碟中，只能一样打一份；而餐盘的容量有限，请问如何搭配出总价格最高的菜肴？



出题者：王新同学


输入

第一行两个整数N,V(1<=N<=8,1<=V<=2000000000),表示菜肴的数量和餐盘的容量。

接下来N行:

每行有两个整数v,w(1<=v<=1000000000,1<=w<=1000000),表示盛装菜肴的菜碟体积和菜肴的价格。


输出

输出最大价格。


输入样例 1

4 5
1 2
2 4
3 4
4 5
输出样例 1

8
提示

N很小可以回溯



实际情况是2022年春节，学校提供3天共9顿免费的餐券，价值大概是早餐7元，中午和下午的是12元。*/
//使用了位运算的dp来解决这个问题
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
int main()
{
	int N;
	ll V;
	cin >> N >> V;
	vector<ll> volumes(N);
	vector<ll> values(N);

	for (int i = 0; i < N; i++)
	{
		cin >> volumes[i] >> values[i];
	}
	ll maxPrice = 0;
	for (int m = 0; m < (1 << N); m++)  // 遍历所有可能的菜肴组合，N很小，可以直接枚举	
	{
		ll totalVolume = 0;
		ll totalValue = 0;
		for (int i = 0; i < N; i++)
		{
			if (m & (1 << i)) // 检查第i位是否为1（是否选择第i道菜）,做与操作
			{
				totalVolume += volumes[i];
				totalValue += values[i];
			}
		}
		if (totalVolume <= V)
		{
			maxPrice = max(maxPrice, totalValue);
		}
	}
	cout << maxPrice << endl;
	return 0;
}