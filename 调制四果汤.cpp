/*
四果汤是厦门地区的著名小吃。小明想喝四果汤，这个四果汤有n个元素（烧仙草、海石花、桃胶、椰果等），可以用前n个字母来表示。

小明在超市看到了T种配料，每种配料也会有一些元素，每个元素也可以用字母来表示（与上述四果汤的定义相同）。将不同的配料混合起来，即可得到一个元素为他们的并集的四果汤。

每种配料都有一个价格。现在小明想花尽量少的钱来购买配料，来调出自己想喝的四果汤，调出来的饮料必须具有他想喝的四果汤的所有特征。



出题人为李哲彦同学


输入

第一行两个数字T, n。表示配料的数量与四果汤特征的数量。

接下来T行，每行一个数字w,表示配料的价格，之后一个字符串，表示这个配料的元素。

T≤1000

n≤15

w≤10000


输出

一行一个整数，最小的价格。如果调不出来，则输出-1


输入样例 1

4 3
5 C
6 B
16 BAC
4 A
输出样例 1

15
输入样例 2

1 2
10 A
输出样例 2

-1
提示

样例1：小明想喝的四果汤元素为ABC,选择1、2、4种配料只需要15元，比选择第3种配料更便宜。

样例2：小明想喝的四果汤元素为AB，但是配料只有A，显然调不出来，故输出-1.*/
//状态压缩dp
//使用二进制移位创造掩码，再进行或运算
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  //取消cin的同步，提高输入速度
	int T, n;
	cin >> T >> n;

	int num_states = 1 << n; // 2^n种状态
	vector<int> dp(num_states, INF); // 初始化dp数组，所有状态的初始值为INF
	dp[0] = 0;
	for (int i = 0; i < T; ++i)
	{
		int w;
		string s;
		cin >> w >> s;  
		int mask = 0;
		for (char c : s) {
			mask |= (1 << (c - 'A'));  //将字符转换为对应的位掩码,不管输入字符的顺序
		}

		for (int j = num_states - 1; j >= 0; --j) {  //一定要倒序遍历,因为所有可能污染 dp[S] 的状态 S_prev (满足 S_prev | mask = S) 都比 S 小，而我们在倒序遍历中还没有访问到它们。
			if (dp[j] != INF) {
				int next_state = j | mask;  //或运算把元素包含进来 
				dp[next_state] = min(dp[next_state], dp[j] + w); //更新状态的最小值
			}
		}
	}
	int target_state = num_states - 1;
	if (dp[target_state] == INF) { //如果目标状态的值仍然是INF，说明无法调出四果汤
		cout << -1 << endl;
	}
	else {
		cout << dp[target_state] << endl;
	}
	return 0;
}
