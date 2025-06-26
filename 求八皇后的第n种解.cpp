/*
掌握基本的递归函数也明白如何生成N皇后问题后，在小华的指导下，小鲁决定加大难度，下一步挑战的就是n皇后问题的升级版：

国际象棋中的皇后可以在横、竖、斜线上不限步数地吃掉其他棋子。

八个皇后问题是如何将八个皇后放在棋盘上（有8 * 8个方格），使它们谁也不能被其他皇后吃掉！

已经知道八皇后问题一共有92组解，每组解可以用一个字符串表示：

对于某个满足要求的八皇后的摆放方法，定义一个皇后串a与之对应，即a=b1b2...b8，其中bi为相应摆法中第i行皇后所处的列数。

题目是：

输入一个数n，要求输出八皇后问题的第n个解，也就是第n个皇后字符串。

串的比较是这样的：皇后串x置于皇后串y之前，当且仅当将x视为整数时比y小。

请你写一个程序，能够根据输入的数n( 1<=n<=92),输出第n个合法的八皇后串。


输入

第1行是测试数据的组数T，后面跟着T行输入。

每组测试数据占1行，包含一个正整数n (1 <= n <= 92)


输出

输出有T行，每行输出对应一个输入。输出应是一个正整数，是第n个八皇后串。


输入样例 1

2
1
92
输出样例 1

15863724
84136275
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<string> solutions;

bool isSafe(vector<int>& board, int row, int col) {
	for (int i = 0; i < row; i++) {
		if (board[i] == col || abs(board[i] - col) == abs(i - row))
			return false;
	}
	return true;
}

void solveNQueensUtil(vector<int>& board, int row) {
	if (row == 8) {
		string solution = "";
		for (int i = 0; i < 8; i++) {
			solution += to_string(board[i] + 1);
		}
		solutions.push_back(solution);
		return;
	}
	for (int col = 0; col < 8; col++) {
		if (isSafe(board, row, col)) {
			board[row] = col;
			solveNQueensUtil(board, row + 1);
		}
	}
}

bool compare(const string& a, const string& b) {
	return a < b;
}

int main()
{
	int T, n;
	cin >> T;

	vector<int> board(8, 0);
	solveNQueensUtil(board, 0);
	sort(solutions.begin(), solutions.end(), compare);
	while (T--) {
		cin >> n;
		cout << solutions[n - 1] << endl;
	}
	return 0;
}