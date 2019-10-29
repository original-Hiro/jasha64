#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 10;
int a[N];

int main()
{
	freopen("input.txt", "w", stdout);
	
	srand(time(NULL));
	printf("%d\n", N);
	a[0] = rand();
	for (int i = 1; i < N; ++i)
	{
		srand(i);
		a[i] = rand();
		a[i - 1] += a[i];
		printf(" %d", a[i - 1]);
	}
	printf(" %d", a[N - 1]);
	
	return 0;
}

