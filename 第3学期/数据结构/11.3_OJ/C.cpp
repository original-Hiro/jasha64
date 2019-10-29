#include <iostream>
using namespace std;

const int N = 100001;
int str[N], sc[N];
int a[N], n;
void Merge()
{
	static int c[N];
	int top1 = 0, top2 = n/2;
	for (int i = 0; i < n; i += 2)
	{
		if (str[a[i]] > str[a[i+1]]) {c[top1++] = a[i]; sc[a[i]]++; c[top2++] = a[i+1];}
		else {c[top1++] = a[i+1]; sc[a[i+1]]++; c[top2++] = a[i];}
	}
	//for (int i = 0; i < n; i++) cout << c[i] << ' '; cout << endl;
	int top = 0;
	top1 = 0; top2 = n/2;
	while (top1 < n/2 || top2 < n)
	{
		if (top2 == n || (top1 < n/2 && (sc[c[top1]] > sc[c[top2]] || (sc[c[top1]] == sc[c[top2]] && c[top1] < c[top2]))))
			a[top++] = c[top1++];
		else a[top++] = c[top2++];
	}
	//for (int i = 0; i < n; i++) cout << a[i] << ' '; cout << endl << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> str[i];
	
	for (int i = 0; i < n; i++) a[i] = i;
	for (int i = 0; i < m; i++) Merge();
	cout << sc[0];
	for (int i = 1; i < n; i++) cout << ' ' << sc[i];
	return 0;
}

