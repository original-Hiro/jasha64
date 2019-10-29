//SPOJ - bubble sort
//归并排序求逆序数 
//这是一个脑筋急转弯的题目，欲求冒泡排序整个过程一共交换了多少次，我们不要被题目迷惑，应该看整体 
//整个冒泡排序过程完成以后，数组变成了顺序，逆序数为0，而每次交换都会使得逆序数减少1，所以答案就等于原数组的逆序数 
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10001, MOD = 10000007;
int res, a[N], c[N];
void Merge_Sort(int b, int e)
{
	if (e <= b+1) return;
	int m = (b + e) / 2;
	Merge_Sort(b, m); Merge_Sort(m, e);
	int top = b, top1 = b, top2 = m;
	while (top1 < m || top2 < e)
	{
		if (top2 == e || (top1 < m && a[top1] <= a[top2])) c[top++] = a[top1++];
		else {res = (res + m - top1) % MOD; c[top++] = a[top2++];}
	}
	copy(c+b, c+e, a+b);
}

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int k = 1; k <= T; k++)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		res = 0;
		Merge_Sort(0, n);
		cout << "Case " << k << ": " << res << endl;
	}
	
	return 0;
}

