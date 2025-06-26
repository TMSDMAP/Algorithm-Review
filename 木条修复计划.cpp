/*
厦门大学的志愿者团队在校园活动中需要使用相同长度的木条来搭建展台。然而，在施工过程中，这些木条被随意截断，每段长度都不超过50。现在，施工团队希望复原原始的木条长度，但他们已经忘记了最初有多少根木条以及它们的长度。

你的任务是帮助他们计算出原始木条可能的最小长度。

出题人：吴泽凯同学



提示：搜索，减枝


输入

第一行是一个整数n，表示截断后的小木条数量。

第二行包含n个整数，表示各个小木条的长度a_i。

1≤n≤65

1≤a_i≤50


输出

输出一个整数，表示原始木条的最小可能长度。


输入样例 1

9
5 2 1 5 2 1 5 2 1
输出样例 1

6*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
// DFS函数：尝试将木条分配到长度为target的原始木条中
bool dfs(vector<int>& sticks, vector<bool>& used, int target, int curr_sum, int start_idx, int remaining_sticks) {
	// 所有木条都已分配，搜索成功
	if (remaining_sticks == 0) return true;
	// 当前木条已填满，开始填下一根
	if (curr_sum == target) {
		return dfs(sticks, used, target, 0, 0, remaining_sticks);
	}
	// 尝试放入不同的木条
	for (int i = start_idx; i < sticks.size(); i++) {
		// 跳过已使用的木条或放不下的木条
		if (used[i] || curr_sum + sticks[i] > target) continue;
		// 剪枝：跳过相同长度且前一个未使用的木条
		if (i > 0 && sticks[i] == sticks[i - 1] && !used[i - 1]) continue;
		used[i] = true;

		if (dfs(sticks, used, target, curr_sum + sticks[i], i + 1, remaining_sticks - 1))
			return true;
		used[i] = false;

		// 关键剪枝：
		// 1. 如果当前是第一个放入的木条且失败，整个方案失败
		// 2. 如果正好填满但失败，整个方案失败
		if (curr_sum == 0 || curr_sum + sticks[i] == target)
			return false;


	}

	return false;
}

int main()
{
	int n;
	cin >> n;
	vector<int> sticks(n);
	for (int i = 0; i < n; i++)
	{
		cin >> sticks[i];
	}
	// 计算总长度和最大木条长度
	int total_length = accumulate(sticks.begin(), sticks.end(), 0);
	int max_length = *max_element(sticks.begin(), sticks.end());
	// 从大到小排序木条，优先放置长木条
	sort(sticks.begin(), sticks.end(), greater<int>());
	// 从可能的最小长度开始尝试
	for (int len = max_length; len <= total_length; len++) {
		// 总长度必须能被目标长度整除
		if (total_length % len != 0) continue;
		vector<bool> used(n, false);
		// 尝试将所有木条分配到长度为len的木条中
		if (dfs(sticks, used, len, 0, 0, n)) {
			cout << len << endl;
			return 0;
		}
	}
	// 如果上面没有返回，说明只能是一根长木条
	cout << total_length << endl;
	return 0;
}