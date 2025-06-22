/*
给定一个含有数字和运算符的字符串，为表达式添加括号，改变其运算优先级以求出不同的结果。你需要给出所有可能的组合的结果。有效的运算符号包含 +, - 以及 * 。


输入

输入为一行字符串


输出

输出为所有可能的结果，每个一行，从小到大排列


输入样例 1

2-1-1
输出样例 1

0
2
输入样例 2

2*3-4*5
输出样例 2

-34
-14
-10
-10
10
*/

//这个题可以用分治来做，递归将字符串拆分成左右两部分，以运算符为分界点，递归来计算，如果result是纯数字，就直接返回，是分治思想的很好体现。


#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>
#include <algorithm>
using namespace std;

string s;
bool visited[100];
vector<int> q;
bool isStringDigital(int start, int end) {
	for (int i = start; i <= end; i++) {
		if (!isdigit(s[i]))
			return false;
	}
	return true;
}

vector<int> different(int start, int end)
{
	vector<int> result;
	if (isStringDigital(start, end))
	{
		result.push_back(stoi(s.substr(start, end - start + 1)));
		return result;
	}
	for (int i = start; i <= end; i++)
	{
		if (s[i] >= '0' && s[i] <= '9') continue;
		vector<int> leftresult = different(start, i - 1);
		vector<int> rightresult = different(i + 1, end);

		for(auto left:leftresult)
			for (auto right : rightresult)
			{
				if (s[i] == '+') result.push_back(left + right);
				else if (s[i] == '-') result.push_back(left - right);
				else if (s[i] == '*') result.push_back(left * right);
			}
	}
	return result;
}

int main()
{
	int t;
	cin >> s;
	q = different(0, s.size() - 1);
	sort(q.begin(), q.end());
	for (auto i : q) cout << i << endl;
}