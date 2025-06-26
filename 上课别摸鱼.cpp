/*
为了 打出 一个字母，Alice 需要 按 对应字母 i 次，i 是该字母在这个按键上所处的位置。

比方说，为了按出字母 's' ，Alice 需要按 '7' 四次。类似的， Alice 需要按 '5' 两次得到字母  'k' 。
注意，数字 '0' 和 '1' 不映射到任何字母，所以 Alice 不 使用它们。
但是，由于传输的错误，Bob 没有收到 Alice 打字的字母信息，反而收到了 按键的字符串信息 。

比方说，Alice 发出的信息为 "bob" ，Bob 将收到字符串 "2266622" 。
给你一个字符串 pressedKeys ，表示 Bob 收到的字符串，请你返回 Alice 总共可能发出多少种文字信息 。

由于答案可能很大，将它对 109 + 7 取余 后返回。



示例 1：

输入：pressedKeys = "22233"
输出：8
解释：
Alice 可能发出的文字信息包括：
"aaadd", "abdd", "badd", "cdd", "aaae", "abe", "bae" 和 "ce" 。
由于总共有 8 种可能的信息，所以我们返回 8 。
示例 2：

输入：pressedKeys = "222222222222222222222222222222222222"
输出：82876089
解释：
总共有 2082876103 种 Alice 可能发出的文字信息。
由于我们需要将答案对 109 + 7 取余，所以我们返回 2082876103 % (109 + 7) = 82876089 。


提示：

1 <= pressedKeys.length <= 105
pressedKeys 只包含数字 '2' 到 '9' 。*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string pressedKeys;
	cin >> pressedKeys;

	int n = pressedKeys.length();
	const int MOD = 1e9 + 7;
	vector<int> dp(n + 1, 0);

	dp[0] = 1; // 空字符串的情况

	for (int i = 1; i <= n; ++i) {
		char c = pressedKeys[i - 1];
        // 方案1: 将第 i 个字符 (pressedKeys[i-1]) 单独解码
        // 方案数等于解码前 i-1 个字符的方案数
        dp[i] = dp[i - 1];

        // 方案2: 如果最后两个字符相同，可以将它们一起解码
        if (i - 2 >= 0 && pressedKeys[i - 2] == c) {
            // 加上解码前 i-2 个字符的方案数
            dp[i] = (dp[i] + dp[i - 2]) % MOD;
        }
        else {
            // 如果不满足两个连续，那也肯定不满足三个或四个连续，可以提前结束
            // 但为了保持和原逻辑完全一致，我们不加这个优化
        }

        // 方案3: 如果最后三个字符相同，可以将它们一起解码
        if (i - 3 >= 0 && pressedKeys[i - 3] == c && pressedKeys[i - 2] == c) {
            // 加上解码前 i-3 个字符的方案数
            dp[i] = (dp[i] + dp[i - 3]) % MOD;
        }

        // 方案4: 如果是'7'或'9'，并且最后四个字符相同，可以将它们一起解码
        if ((c == '7' || c == '9') && i - 4 >= 0 && pressedKeys[i - 4] == c && pressedKeys[i - 3] == c && pressedKeys[i - 2] == c) {
            // 加上解码前 i-4 个字符的方案数
            dp[i] = (dp[i] + dp[i - 4]) % MOD;
        }
	}
	cout << dp[n] << endl;
	return 0;
}