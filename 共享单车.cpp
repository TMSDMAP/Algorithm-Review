/*
A 同学是 XMUer，每天都使用共享自行车从国光宿舍骑到学武楼。共享自行车省去了维护的成本，但是单次使用的价格很贵，他看到了一种省钱的方法：购买通票。通票可以在有效期内无限次使用。通票的有效期计算精确到天。A 同学可以购买通票，也可以单次付费。

已知单次使用共享自行车的价格是 m0 元。有 K 种通票，第 i 种通票的有效期是 ti 天， 价格是 ci 元。

A同学想知道，对于给定接下来 D 天，每天使用共享自行车的次数已知，求最小的花费。



出题人为王则宇同学


输入

输入数据的第一行有 2 个整数，分别是 D， K。

接下来一行有 D 个整数，表示从第 1 天至第 D 天，每天使用共享单车的次数 di。

接下来 K 行，每行
2
2 个整数，表示 ti 和 ci。

接下来一行，有一个整数。表示单次使用的价格 m0

1<D<3000，1<K<10

1<ti<180，1 <ci<500

1<m0<10，0<di<20


输出

输出一个整数，表示最少的花费。


输入样例 1

10 2
1 0 0 0 5 4 0 1 2 0
1 5
2 7
2
输出样例 1

15
提示

假设10天的日期下标是1～10。
第1天使用1次，单次付费，花费2元。第5、6天，
购买两天的通票，花费7元。第8天，单次付费，花费2元。
第9天，单次付费，使用了两次，花费4元。*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long INF = 1e18;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int D, K;
	cin >> D >> K;

	vector<int> d(D);
	for (int i = 0; i < D; ++i) {
		cin >> d[i];
	}

	vector<pair<int, int>> passes(K);
	for (int i = 0; i < K; ++i) {
		cin >> passes[i].first >> passes[i].second;
	}
	int m0;
	cin >> m0;

	vector<long long> dp(D + 1, INF); // dp[i] 表示前 i 天的最小花费
	dp[0] = 0; // 第0天不花钱

	for (int i = 1; i <= D; ++i) {
		// 方案1: 第 i 天单独付费
		// 花费是覆盖前 i-1 天的最小花费 + 第 i 天的费用
		// d数组是0-indexed, 所以第i天对应d[i-1]
		dp[i] = dp[i - 1] + d[i - 1] * m0; // 单次付费
		// 方案2: 考虑使用某张通票，且这张通票的有效期在第 i 天结束
		for (int k = 0; k < K; ++k) {
			int t = passes[k].first; // 通票有效期
			int c = passes[k].second; // 通票价格
			// 这张通票覆盖了从 (i - t + 1) 到 i 的日子
			// 我们需要找到覆盖到 i - t 天的最小花费
			// 如果 i - t < 0, 说明这张票从第一天就开始用了, 之前花费为dp[0]
			int preev_day_idx = max(0, i - t); // 有效期开始的前一天索引
			long long cost_with_pass = dp[preev_day_idx] + c; // 使用通票的总花费

			// 更新 dp[i]，取最小值
			dp[i] = min(dp[i], cost_with_pass);
		}
	}
	cout << dp[D] << endl; // 输出前 D 天的最小花费

	return 0;
}