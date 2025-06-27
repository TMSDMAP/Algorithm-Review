/*
给你一个长为n的字符串s以及a_{1..n}，删去第i个字符的代价为a_i，你需要删去一些字符（如果一开始就符合条件当然可以不删）使得剩下的串中不含子序列"jxnu"，求最小代价。

出题人：张俊圣同学


输入

第一行包含一个整数n(1≤n≤10^5)，即语句的长度。

第二行包含一个长度为n的字符串s，由小写字母组成

第三行包含n个整数a_1,a_2，…，a_n(0≤a_i≤998244353)。


输出

在删除一些(也可能不删)字符后，输出最小代价。


输入样例 1

6
jjxnuj
3 2 9 11 7 1
输出样例 1

5
提示

子序列不需要连续。*/

/*
本题的思路是动态规划。
我们定义一个DP数组，其中dp[i]表示为了使字符串不含 "jxnu" 的前 i 个字符作为子序列
（例如 dp[0] 对应 "j"，dp[1] 对应 "jx"）所需的最小代价。
遍历输入字符串，当遇到构成 "jxnu" 的字符时，
我们更新DP状态。例如，当遇到字符 'x' 时，
为了避免形成 "jx"，我们有两个选择：
一是删除这个 'x'，
成本为当前删除代价加上原先避免 "jx" 的成本 dp[1]；
二是保留这个 'x'，但前提是它之前必须没有 "j" 子序列，
成本为避免 "j" 的成本 dp[0]。我们取两者中的较小值更新 dp[1]。
依此类推，遍历完整个字符串后，dp[3] 即为最终答案。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<long long> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	vector<long long> dp(4, 0);

	for (int i = 0; i < n; i++) {
		if (s[i] == 'j')
			dp[0] += a[i];
		else if (s[i] == 'x')
			dp[1] = min(dp[1] + a[i], dp[0]);
		else if (s[i] == 'n')
			dp[2] = min(dp[2] + a[i], dp[1]);
		else if (s[i] == 'u')
			dp[3] = min(dp[3] + a[i], dp[2]); 
	} 
	cout << dp[3] << endl;
	return 0;
}