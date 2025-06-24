#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

#define EPS 1e-6
#define spacesize 4
vector<double> input(spacesize + 1); // 输入的四个数

bool isZero(double x) // 判断一个数是否接近于0
{
	return fabs(x) <= EPS;
}

bool count24(vector<double> a, int n) 
{
	if (n == 1)
	{
		return isZero(a[0] - 24);  // 判断是否等于24
	}
	else
	{
		for(int i = 0;i<n-1;i++)  
			for (int j = i + 1; j < n; j++)  
			{
				vector<double> temp(n - 1, 0);  // 临时存储结果
				int iTemp = 0;
				for (int k = 0; k < n; k++)
				{
					if ((k != i) && (k != j)) temp[iTemp++] = a[k];  // 将除去a[i]和a[j]的其他数存入temp中
				}

						temp[iTemp] = a[i] + a[j];
						if (count24(temp, n - 1)) return true;  // 加法
						temp[iTemp] = a[i] - a[j];
						if (count24(temp, n - 1)) return true; // 减法
						temp[iTemp] = a[j] - a[i];
						if (count24(temp, n - 1)) return true;  // 减法
						temp[iTemp] = a[i] * a[j];
						if (count24(temp, n - 1)) return true;  // 乘法
						if (!isZero(a[j]))
						{
							temp[iTemp] = a[i] / a[j];
							if (count24(temp, n - 1)) return true;  // 除法
						}
						if (!isZero(a[i]))
						{
							temp[iTemp] = a[j] / a[i];
							if (count24(temp, n - 1)) return true; // 除法
						}
				
			}
	}
	return false;
}

int main()
{
	while (true)
	{
		bool isEndInput = true;
		for (int i = 0; i < spacesize; i++)
		{
			cin >> input[i];
			if (input[i] != 0) isEndInput = false;
		}
		if (isEndInput) break;  // 输入0 0 0 0时结束程序
		if (count24(input, spacesize))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}