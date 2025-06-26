/*
在一个布满宝藏的迷宫中，高桥从左上角的起点出发，目标是通过连续的移动到达右下角。迷宫由H行W列的方格组成，每个方格中都有一个整数，代表该方格中宝藏的类型。高桥每次可以选择向右或向下移动，直到他到达终点。

如果在走出迷宫的整个路径上，高桥找到的所有宝藏类型都不相同，他会觉得非常有成就感（即经过的每个方格上的数字都不相同，包括起点和终点）。请计算有多少条从起点到终点的路径满足这个条件。

出题人：梁辰景同学


输入

第一行包含两个整数H和W，表示迷宫的行数和列数。

接下来的H行，每行包含W个整数，表示每个方格上的宝藏类型a_{ij}。


输出

输出满足条件的路径数量


输入样例 1

3 3
3 2 2
2 1 3
1 5 4
输出样例 1

3
提示

对于给出的示例中的迷宫：

路径(1,1)→(1,2)→(1,3)→(2,3)→(3,3)由于经过的宝藏类型重复（有类型2出现两次），所以高桥不会有成就感。

路径(1,1)→(1,2)→(2,2)→(3,2)→(3,3)经过的宝藏类型分别是3, 2, 1, 5, 4，都不重复，所以高桥会觉得非常有成就感。

数据范围：

2<=H<=10,2<=W<=10

1<= a_{ij}=1e9
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int H, W;
vector<vector<int>> grid;
long long count_paths = 0;


void dfs(int r, int c, unordered_set<int>& visited) {
	if (visited.count(grid[r][c]))
		return;
	if (r == H - 1 && c == W - 1) {
		count_paths++;
		return;
	}

	visited.insert(grid[r][c]);

	if (r + 1 < H) {
		dfs(r + 1, c, visited); // 向下移动
	}
	if (c + 1 < W) {
		dfs(r, c + 1, visited); // 向右移动
	}
	visited.erase(grid[r][c]); // 回溯
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> H >> W;
	grid.resize(H, vector<int>(W));

	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cin >> grid[i][j];
		}
	}
	unordered_set<int> initial_visited;
	dfs(0, 0, initial_visited); // 从起点开始深度优先搜索
	cout << count_paths << endl; // 输出满足条件的路径数量
	return 0;
}