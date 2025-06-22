#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

const int N = 40;

int n;
int post[N], in[N];

unordered_map<int, int> l, r, pos;

int build(int il, int ir, int pl, int pr)
{
	int root = post[pr];
	int k = pos[root];
	if (il < k) l[root] = build(il,k-1,pl,pl+(k-1)-il);//左子树
	if (ir > k) r[root] = build(k+1,ir,pl+k-il,pr-1);//右子树
	return root;
}

void bfs(int root)
{
	queue<int> q;
	q.push(root);
	while (!q.empty())
	{
		auto t = q.front();
		q.pop();
		cout << t << " ";
		if (l.count(t)) q.push(l[t]); // 左子树
		if (r.count(t)) q.push(r[t]); // 右子树
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> post[i];
	for (int i = 0; i < n; i++)
	{
		cin >> in[i];
		pos[in[i]] = i;//存储中序遍历的索引
	}
	int root = build(0, n - 1, 0, n - 1);
	bfs(root);
	return 0;
}