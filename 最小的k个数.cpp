/*
输入包含n个整数的数列，找出其中最小的k个数

O(nlogn)的算法很容易想到，你能想到更优的算法吗


输入

第一行包含两个整数 n 和 k。

第二行包含 n 个整数，表示整数数列。

数据范围：

1 <= k <= n <= 100000


输出

输出包含k个整数表示数列中最小的k个数（输出顺序任意）


输入样例 1

8 4
1 3 5 7 2 4 6 8
输出样例 1

1 2 3 4
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> nums(n);
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
	priority_queue<int> maxHeap;

	for (int i = 0; i < k; i++) {
		maxHeap.push(nums[i]);
	}
	for (int i = k; i < n; i++) {
		if (nums[i] < maxHeap.top()) {
			maxHeap.pop();
			maxHeap.push(nums[i]);
		}
	}

	// 将堆中元素存入vector以便排序
	vector<int> result;
	while (!maxHeap.empty()) {
		result.push_back(maxHeap.top());
		maxHeap.pop();
	}

	// 由于大顶堆输出的是从大到小，需要反转为从小到大
	reverse(result.begin(), result.end());

	// 输出结果
	for (int num : result) {
		cout << num << " ";
	}

	return 0;
}