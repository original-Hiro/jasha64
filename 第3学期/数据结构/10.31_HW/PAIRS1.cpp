//SPOJ - count the pairs
//排序，完成排序后所有元素对应的答案只需要遍历一次就可以全部得到了，总时间复杂度O(nlogn) 
#include <iostream>
#include <algorithm>
using namespace std;

int a[100001];

int main()
{
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	if (k < 0) k = -k;
	else if (k == 0) {cout << 0 << endl; return 0;}
	for (int i = 0; i < n; i++) cin >> a[i];
	
	sort(a, a+n);
	int res = 0;
	for (int i = 0, j = 1; i < n; i++)
	{
		while (j < n && (long long)a[j] - a[i] < k) j++; //given all numbers are distinct
		if (j < n && (long long)a[j] - a[i] == k) res++;
		//这是题目自己的问题，题目说everything can be done with 32-bit integers，实际上两个int相减可能超出int范围 
	}
	cout << res << endl;
	
	return 0;
}

