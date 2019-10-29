#include <cstdio>
#include <cstring>
using namespace std;

const int N = 7;
int n;
char a[N], b[N];
bool v[N];

void Permutation(int Cur)
{
	if (Cur == n) {printf("%s\n", b); return;}
	for (int i = 0; i < n; ++i)
		if (!v[i])
		{
			v[i] = true;
			b[Cur] = a[i];
			Permutation(Cur + 1);
			v[i] = false;
		}
}

int main()
{
	scanf("%s", a);
	n = strlen(a);
	
	Permutation(0);
	
	return 0;
}

