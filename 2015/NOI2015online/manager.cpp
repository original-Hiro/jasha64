#include <iostream>
#include <cstring>
using namespace std;

const int N1 = 100007, N2 = 5007;
int n, f[N1];
bool Installed[N1];
struct MYJ_Array
{
	int Data[N2], Top;
	
	void push(const int& x) {Data[Top++] = x;}
	int size() {return Top;}
	bool empty() {return !Top;}
	
	int& operator [] (const int& x) {return Data[x];}
};
struct Tree
{
	int Data;
	MYJ_Array Next;
} t[N2];

void Uninstall(const int& x, int& Res)
{
	Installed[x] = false;
	Res++;
	for (int i = 0; i < t[x].Next.size(); i++)
		if (Installed[t[x].Next[i]]) Uninstall(t[x].Next[i], Res);
}
void Solve1()
{
	int q, c;
	char argv[10];
	int i, Res;
	
	for (i = 1; i < n; i++)
	{
		scanf("%d", &f[i]);
		t[f[i]].Next.push(i);
	}
	cin >> q;
	for (i = 0; i < q; i++)
	{
		Res = 0;
		scanf(" %s%d", argv, &c);
		if (argv[0] == 'i')
			while (!Installed[c])
			{
				Installed[c] = true;
				Res++;
				c = f[c];
			}
		else if (Installed[c]) Uninstall(c, Res);
		printf("%d\n", Res);
	}
}
void Solve2()
{
	int q, c;
	char argv[10];
	int i, Res;
	
	for (i = 1; i < n; i++) scanf("%d", &f[i]);
	cin >> q;
	for (i = 0; i < q; i++)
	{
		Res = 0;
		scanf(" %s%d", argv, &c);
		if (argv[0] == 'u') return;
		while (!Installed[c])
		{
			Installed[c] = true;
			Res++;
			c = f[c];
		}
		printf("%d\n", Res);
	}
}

int main()
{
	freopen("manager.in", "r", stdin);
	freopen("manager.out", "w", stdout);
	
	cin >> n;
	if (n <= 5000) Solve1();
	else Solve2();
	
	return 0;
}

