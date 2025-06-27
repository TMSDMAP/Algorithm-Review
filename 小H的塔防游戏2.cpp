/*
小H在你的帮助下成功通过了塔防游戏1.

现在来到了第二关,有一个n*n的地图,地图中'X'代表障碍物,'.'代表空地.

小H需要在空地上建防御塔,规定任意两个防御塔不能位于同一行或者同一列,除非它们之间有障碍物

请你帮助小H计算最多能建多少个防御塔


输入

第一行一个n(2<=n<=4),表示地图的大小

4*4的矩形,矩形的每个元素为'X'或'.',分别表示障碍物和空地


输出

输出防御塔的最大个数


输入样例 1

4
.X..
....
XX..
....
输出样例 1

5
*/


#include <iostream>
#include <vector>
using namespace std;
vector<int> x, y;
char graph[4][4];
int n, maximum = 0;
bool check(int x1, int y1) {
	for (int i = 0; i < x.size(); i++) {
		if (x1 == x[i]) {
			bool flag = false;
			for (int j = min(y1, y[i]) + 1; j < max(y1, y[i]); j++) {
				if (graph[x1][j] == 'X') {
					flag = true;
				}
				
			}
			if (!flag) return flag;
		}  //检查是否与同一行的防御塔冲突
		if (y1 == y[i]) {
			bool flag = false;
			for (int j = min(x1, x[i]) + 1; j < max(x1, x[i]); j++) {
				if (graph[j][y1] == 'X') {
					flag = true;
				}
				
			}
			if (!flag) return flag;
		} //检查是否与同一列的防御塔冲突
	}
	return true;  //如果没有冲突则返回true
}

void restore(int row) {
	for (int i = x.size() - 1; i >= 0;i--) {
		if (x[i] == row) {
			x.erase(x.begin() + i);
			y.erase(y.begin() + i);
		}
	}
}//除去同一行所有防御塔

void seek(int row) {
	if (row == n) {
		int k = x.size();  
		maximum = max(maximum, k); // 更新最大值
		return;
	}

	for (int i = 0; i < n; i++) {
		if (graph[row][i] == '.' && check(row, i)) {
			x.push_back(row);
			y.push_back(i);
			for(int j = 0;j<n;j++)
				if (graph[row][j] == '.' && check(row, j) && j != i) {
					x.push_back(row);
					y.push_back(j);
				}
			seek(row + 1); // 递归到下一行
			restore(row); // 恢复状态
		}
	}
}

int main() {
	cin >> n;
	for(int i = 0;i<n;i++)
		for(int j = 0;j<n;j++)
			cin >> graph[i][j];
	seek(0);
	cout << maximum << endl;
	return 0;
}