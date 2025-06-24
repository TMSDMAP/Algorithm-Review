/*
有N只蚂蚁在数轴上爬行，第i只蚂蚁的初始坐标为Xi​，字符串S表示蚂蚁的爬行方向，每只蚂蚁每秒向固定方向爬一格,Si​表示第i只蚂蚁的爬行方向：

Si​=0表示下标为Xi​的蚂蚁面朝数轴负方向，Si​​=1表示下标为Xi​​的蚂蚁面朝数轴正方向

若有两蚂蚁相遇，他们既不改变速度也不改变方向，请问在T秒以内（包含T秒），有多少只蚂蚁相遇？

出题人：高鑫辉同学


输入

第一行包含两个整数N和T，N表示蚂蚁的数量，T表示给定的时间。

接下来的一行包含长度为N的字符串S，表示每个蚂蚁的移动方向

接下来的一行包含N个整数Xi，表示每个蚂蚁的初始位置


输出

一个整数，表示在T秒以内（包含T秒），有多少只蚂蚁相遇？


输入样例 1

6 3
101010
-5 -1 0 1 2 4
输出样例 1

5*/
//只有不同方向的蚂蚁才可能相遇(正方向与负方向)
//相同方向的蚂蚁之间距离保持不变，永远不会相遇
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
ll N, T;
const int MAXN = 200005;
char S[MAXN];
ll X[MAXN];

int main()
{
	cin >> N >> T;
	for (int i = 0; i < N; i++)
		cin >> S[i];
	for (int i = 0; i < N; i++)
		cin >> X[i];
	vector<int> right, left;
	for (int i = 0; i < N; i++)
	{
		if (S[i] == '1') // 面朝正方向
			right.push_back(X[i]);
		else // 面朝负方向
			left.push_back(X[i]);
	}
	sort(right.begin(), right.end());
	sort(left.begin(), left.end());
	ll ans = 0;
	for (int i = 0; i < right.size(); i++) //对于每只向右移动的蚂蚁(位置为right[i])：
	{
		int l = lower_bound(left.begin(), left.end(), right[i]) - left.begin();
		int r = upper_bound(left.begin(), left.end(), right[i] + 2 * T) - left.begin();
		ans += r - l;
	}
	/*
	当两只蚂蚁相向而行时，它们的相对速度是每秒2格
	如果向左蚂蚁的初始位置 ≤ right[i] + 2*T，则在T秒内一定会与向右蚂蚁相遇
	如果初始位置在right[i]之前，则已经错过了
	所以相遇条件是：right[i] ≤ left位置 ≤ right[i] + 2*T*/
	cout << ans << endl;
	return 0;
}
