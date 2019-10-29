#include <iostream>
#include <algorithm>
using namespace std;

int a[5007], n;

void Sort(int Begin, int End)
{
	int Left = Begin, Right = End, Watcher = a[(Begin + End) >> 1];
	while (Left <= Right)
	{
		while (a[Left] > Watcher) Left++;
		while (a[Right] < Watcher) Right--;
		if (Left <= Right) swap(a[Left++], a[Right--]);
	}
	if (Right > Begin) Sort(Begin, Right);
	if (Left < End) Sort(Left, End);
}

int main()
{
	int i;
	
	cin >> n;
	for (i = 1; i <= n; i++) cin >> a[i];
	
	Sort(1, n);
	
	cout << a[1];
	for (i = 2; i <= n; i++) cout << ' ' << a[i];
	cout << endl;
	
	return 0;
}

