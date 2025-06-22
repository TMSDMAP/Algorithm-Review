/*
小鲁参加一年一度的信息学院辩论赛，这样的比赛对他简直是如鱼得水游刃有余，这不，经过3小时激烈的辩论，小鲁很轻松的驳倒众人，让众选手哑口无言。

这次比赛采取网络投票，每个在线观看辩论赛的ID都可以评分，评分规则为：为去掉一个最高分和一个最低分，然后计算平均得分。

比赛结束后，由于大众评委众多，成绩难以手工统计。热心的小鲁找到满头大汗的评委，笑着说，这事容易，我来写个程序搞定这事！


输入

输入数据有多组，每组占一行，每行的第一个数是n(2<n<=100)，表示评委的人数，然后是n个评委的打分。


输出

对于每组输入数据，输出选手的得分，结果保留2位小数，每组输出占一行。


输入样例 1

3 96 98 97
4 96 99 98 97
输出样例 1

97.00
97.50*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while (cin >> n) {
		vector<int> scores(n);
		for (int i = 0; i < n; ++i) {
			cin >> scores[i];
		}
		sort(scores.begin(), scores.end());
		double sum = 0;
		for (int i = 1; i < n - 1; ++i) { // 去掉最高分和最低分
			sum += scores[i];
		}
		double average = sum / (n - 2);
		cout << fixed << setprecision(2) << average << endl; // 输出保留两位小数

	}
}

