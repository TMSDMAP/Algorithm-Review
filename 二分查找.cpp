/*
请实现有重复数字的有序数组的二分查找。

输出在数组中第一个大于等于查找值的位置，如果数组中不存在这样的数，则输出数组长度加一。


输入

输入第一行有两个数，第一个数为数组长度n（≤10^6），第二个数为需要查找的数。

接下来有n个整数，以空格或换行符分隔。


输出

输出待查找的数的位置。*/

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e6;
int a[N + 1];
int binary_search(int l, int r, int target)
{
	while (l < r)
	{
		int mid = l + (r - l) / 2;
		if (a[mid] >= target)
			r = mid;  //不能l=r，这样会死循环
		else l = mid + 1;
	}
	return l;
}

int main()
{
	int n, target;
	cin >> n >> target;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int index = binary_search(0, n-1, target);
	cout << index+1 << endl;
	return 0;
}