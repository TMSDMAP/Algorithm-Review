/*
小h非常喜欢和投骰子有关的游戏，所以小s叫小h来玩他做的新游戏。游戏规则很简单，有n+1个格子，到达第i个格子即可获得一个快乐值a_i。小h的运动由一个6面骰子决定，但小h是投骰子高

手，所以他可以操纵骰子的点数。

初始时，小h站在第0个格子，快乐值为0（即保证a_0=0），小h必须移动k次，请你帮忙制定一个策略，以便于他能够获得尽可能多的快乐值。

出题人：宋浩元同学


输入

第一行包含两个整数n和k，分别表示格子的数量和最多移动的次数。范围为1<=n<=1e4，1<=k<=min(1e3,n/6)。

第二行包含n+1个整数a_i，表示每个格子的快乐值。范围为-1e9<=a_i<=1e9。


输出

第一行输出一个整数，表示小h能够获得的最大快乐值。

第二行输出对应策略，即走过的格子，如果有多种策略，请你输出终点离起点最近的一种策略，因为小h很懒


输入样例 1

12 2
0 3 -5 6 -8 -21 -7 -3 -7 1 21 69 233
输出样例 1

226
6 12
提示

在样例中，小h可以按以下策略移动：

第一次移动到第6个格子，获得快乐值-7。

第二次移动到第12个格子，获得快乐值233。

总共获得的快乐值为-7+233=226。*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long INF = -1e18;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<long long> a(n + 1);
	for (int i = 0; i <= n; ++i) {
		cin >> a[i];
	}
	vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, INF));
	vector<vector<int>> path(k + 1, vector<int>(n + 1, 0));

	dp[0][0] = 0; // 初始状态

	//j:当前是第几次移动
	for (int j = 1; j <= k; ++j) {
		//i:本次移动的目标格子
		for (int i = 1; i <= n; ++i) {
			long long max_prev_dp = INF;
			int pre_pos = -1;

			for (int d = 1; d <= 6; ++d) {
				if (i - d >= 0) {
					if (dp[j - 1][i - d] > max_prev_dp) {
						max_prev_dp = dp[j - 1][i - d];
						pre_pos = i - d;
					}
				}
			}  //选择前6个格子中的最大值

			if (max_prev_dp != INF) {
				dp[j][i] = max_prev_dp + a[i];
				path[j][i] = pre_pos; // 记录路径
			}
		}
	}
	long long max_happiness = -1;  
	int final_pos = -1;
	for (int i = 1; i <= n; ++i) {
		if (dp[k][i] > max_happiness) {
			max_happiness = dp[k][i];
			final_pos = i;
		}
	}  //找到第k次移动后最大快乐值和对应的格子,不能取等！
	cout << max_happiness << endl;
	vector<int> result_path;
	int current_pos = final_pos;
	for (int j = k; j >= 1; --j) {
		result_path.push_back(current_pos);
		current_pos = path[j][current_pos];
	}  //回溯路径
	reverse(result_path.begin(), result_path.end());
	for (int i = 0; i < result_path.size(); ++i) {
		if (i > 0) cout << " ";
		cout << result_path[i];
	}  //输出路径
	cout << endl;
	return 0;
}