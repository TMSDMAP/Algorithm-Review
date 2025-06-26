/*
XBB 是一名 ai 训练大师，她想要训练出世界上最强的 ai。

XBB 的训练方法和其他人有些不同。XBB参照大群的进化方式，自创了一套 ai 融合训练法：她可以任取两个 ai ，将它们融合起来，形成一个新的 ai。根据 XBB 丰富的经验，如果融合前两个 ai 素材的综合能力值为 x 和 y ，那么融合后 ai 的综合能力值总是 (x+y)/2 。XBB 也认为，同一个 ai 只能作为素材被使用一次，否则会导致整个 ai 的崩坏。

XBB 现在有 n 个 ai ，并且知道每个 ai 的综合能力值  s_i。她想把这些 ai 都融合在一起，那么她能融合出的最强 ai 的能力值是多少？

出题人：栾英石同学


输入

第一行一个整数n 。

第二行n 个正整数 a_i，如题意所示


输出

一行一个数，表示最强ai 的能力值，保留两位小数。


输入样例 1

5
3 1 3 3 8
输出样例 1

5.38
提示

数据范围：

1<=n<=1000000；1<=a_i<=1000

后记：XBB 费了大力气都融合到一起之后发现融合出来的 ai 永远没有融合之前的强，怎么会是呢。*/

#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
	int n;
	cin >> n;

	priority_queue<double, vector<double>, greater<double>> pq;

	for (int i = 0; i < n; ++i) {
		double val;
		cin >> val;
		pq.push(val);
	}
	while (pq.size() > 1) {
		double a = pq.top();
		pq.pop();
		double b = pq.top();
		pq.pop();

		double merged = (a + b) / 2.0;
		pq.push(merged);
	}
	cout << fixed << setprecision(2) << pq.top() << endl;
	return 0;
}
/*
当融合两个AI时，得到的新AI能力值总是小于等于两者中较大的值。

这意味着高能力值的AI会"拉低"最终的结果。所以最优策略是：每次都选择当前能力值最小的两个AI进行融合，这样能最大程度地保留高能力值AI的贡献。

算法步骤
将所有AI放入最小堆（优先队列）
每次取出堆中两个能力值最小的AI进行融合
将融合产生的新AI放回堆中
重复步骤2-3，直到堆中只剩一个AI
剩下的AI就是能力值最大的融合结果
*/