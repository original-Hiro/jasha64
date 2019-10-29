#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100007;
int a[N], b[N], c[N], p[N];

inline int Abs(int x) {return x < 0 ? -x : x;}
inline void Merge_Sort(int* A, const int& begin, const int& end, int* C)
{
	if (end <= begin + 1) return;
	int mid = (begin + end) / 2, top1 = begin, top2 = mid, top = begin;
	Merge_Sort(A, begin, mid, C);
	Merge_Sort(A, mid, end, C);
	while (top1 < mid || top2 < end)
	{
		if (top2 >= end || (top1 < mid && A[top1] <= A[top2])) C[top++] = A[top1++];
		else {C[top++] = A[top2]; b[A[top2++]] += mid - top1;}
	}
	copy(C + begin, C + end, A + begin);
}

int main()
{
	int T;
	
	ios::sync_with_stdio(false);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {cin >> a[i]; p[a[i]] = i;}
		
		fill(b, b + N, 0);
		Merge_Sort(a, 1, n+1, c);
		
		for (int i = 1; i <= n; i++) p[i] -= b[i];
		cout << "Case #" << t << ':';
		for (int i = 1; i <= n; i++) cout << ' ' << max(b[i], Abs(i - p[i]));
		cout << endl;
	}
	
	return 0;
}

