#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100007;
int a[N], c[N];

inline void Merge_Sort(int* A, const int& begin, const int& end, int* C)
{
	if (end <= begin + 1) return;
	int mid = (begin + end) / 2, top1 = begin, top2 = mid, top = begin;
	Merge_Sort(A, begin, mid, C);
	Merge_Sort(A, mid, end, C);
	while (top1 < mid || top2 < end)
	{
		if (top2 >= end || (top1 < mid && A[top1] >= A[top2])) C[top++] = A[top1++];
		else C[top++] = A[top2++];
	}
	copy(C + begin, C + end, A + begin);
}

int main()
{
	int n;
	int i;
	
	cin >> n;
	for (i = 0; i < n; i++) cin >> a[i];
	
	Merge_Sort(a, 0, n, c);
	
	cout << a[0];
	for (i = 1; i < n; i++) cout << ' ' << a[i];
	cout << endl;
	
	return 0;
}

