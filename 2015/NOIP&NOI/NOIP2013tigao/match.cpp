#include <fstream>
#include <algorithm>
using namespace std;

ifstream cin("match.in");
ofstream cout("match.out");
const int N = 100007, MOD = 99999997;
int a[N], f[N], c[N], res;

inline void Merge_Sort(int* A, const int& begin, const int& end, int* C)
{
	if (end <= begin + 1) return;
	int mid = (begin + end) / 2, top1 = begin, top2 = mid, top = begin;
	Merge_Sort(A, begin, mid, C);
	Merge_Sort(A, mid, end, C);
	while (top1 < mid || top2 < end)
	{
		if (top2 >= end || (top1 < mid && A[top1] <= A[top2])) C[top++] = A[top1++];
		else {C[top++] = A[top2++]; res = (res + mid - top1) % MOD;}
	}
	copy(C + begin, C + end, A + begin);
}

int main()
{
	int n;
	int i, cache;
	
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> cache;
		f[cache] = i + 1;
	}
	for (i = 0; i < n; i++)
	{
		cin >> cache;
		a[i] = f[cache];
	}
	
	Merge_Sort(a, 0, n, c);
	
	cout << res << endl;
	
	return 0;
}

