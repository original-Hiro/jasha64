#include <iostream>
using namespace std;

int a[21], n;
bool Search(int cur, int tar)
{
	if (tar == 0) return 1;
	for (int i = cur+1; i < n; i++)
		if (Search(i, tar-a[i])) return 1;
	return 0;
}

int main()
{
	int s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++)
		if (Search(i, s-a[i])) {cout << "^_^" << endl; return 0;}
	cout << "QAQ" << endl;
	return 0;
}

