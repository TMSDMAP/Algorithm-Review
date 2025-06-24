/*
清风徐来，水波不兴，在芙蓉湖泛舟是一件很惬意的事情。一些同学选修过相关体育课程后，想要加入舟艇队，前往在芙蓉湖泛舟，但是每个同学需要选择带练的教练：

1.每个教练都有多个心仪的学生。

2.每个教练最终只能选择一名学生带练。

3.每个学生只能分配到一名教练带练。

现在你是该舟艇队的志愿者，现收集到了所有教练的意向。你要如何进行教练的分配，使得最多数量的教练能够指导心仪学生。


输入

输入数据包含多个测试实例：

每个测试实例的第一行是三个整数k,m,n，分别表示可能的组合数目，教练的人数，学生的人数。(0<k<=1000,1<=m,n<=500)

接下来包含k行，每行有两个数，表示教练Ai愿意指导学生Bi。


输出

对于每个测试实例，输出一个整数，表示能够找到心仪学生的最多教练数。


输入样例 1

7 4 4
1 1
1 2
1 3
2 1
2 4
3 1
4 2
输出样例 1

4*/

//二分图匹配，匈牙利树
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 501;
vector<int> g[MAXN];
int match[MAXN]; // 匹配数组，match[v]表示v匹配的u，如果没有匹配则为-1
bool visited[MAXN]; // 访问标记数组，visited[v]表示v是否被访问过

bool dfs(int u) {  
	for (int v : g[u]) {
		if (visited[v]) continue;
		visited[v] = true;
		if (match[v] == -1 || dfs(match[v])) {
			match[v] = u;
			return true;
		} // 如果v没有匹配或者可以找到一个新的匹配，则将u匹配到v上
	}
	return false;
}

int hungarian(int m) {
	memset(match, -1, sizeof(match)); // 初始化匹配数组为-1，表示没有匹配
	int result = 0;
	for (int i = 0; i < m; i++) {
		memset(visited, false, sizeof(visited));  // 初始化访问标记数组为false
		if (dfs(i)) result++;  // 如果找到一个匹配，则结果加1
	}
	return result;
}

int main()
{
	int k, m, n;
	while (cin >> k >> m >> n)
	{
		for (int i = 0; i < m; i++) g[i].clear();
		for (int i = 0; i < k; i++)
		{
			int a, b;
			cin >> a >> b;
			g[a - 1].push_back(b - 1); // 教练编号从0开始
		}
		int result = hungarian(m);
		cout << result << endl;
	}
	return 0;
}