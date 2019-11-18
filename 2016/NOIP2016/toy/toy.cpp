//"CTSC" 2016
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 100007;
int Dir[N];
char na[N][17];

inline int Direction(int cur, int d) {return (Dir[cur] ^ d) ? 1 : -1;}

int main()
{
	freopen("toy.in", "r", stdin);
	freopen("toy.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {scanf("%d", &Dir[i]); scanf("%s", na[i]);}
	
	int d, s, cur = 0;
	while (m--)
	{
		scanf("%d%d", &d, &s);
		int Newp = (cur + Direction(cur, d) * s + n) % n;
		cur = Newp;
	}
	
	printf("%s\n", na[cur]);
	
	return 0; //บรฬโ 
}

