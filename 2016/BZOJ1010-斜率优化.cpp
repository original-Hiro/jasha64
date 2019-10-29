#include <iostream>
#include <cstdio>
using namespace std;

const int N = 50007;
long long s[N], f[N], g[N], x[N], q[N];
int n, l, front = 0, rear = 0;

inline long long y(int a) {return f[a - 1] + x[a] * x[a];}
inline double slop(int a, int b) {return (y(a) - y(b)) / (double)(x[a] - x[b]);}
void DP()
{
	for (int i = 1; i <= n; i++)
	{
		while (rear > front + 1 && slop(i, q[rear - 1]) < slop(q[rear - 1], q[rear - 2])) --rear;
		q[rear++] = i;
		while (rear > front + 1 && slop(q[front + 1], q[front]) < 2 * g[i]) ++front;
		f[i] = f[q[front] - 1] + (g[i] - x[q[front]]) * (g[i] - x[q[front]]);
	}
}

int main()
{
	cin >> n >> l;
	for (int i = 1; i <= n; i++) {scanf("%d", &s[i]); s[i] += s[i - 1]; g[i] = i + s[i] - l; x[i] = i + s[i - 1];}
	
	DP();
	
	cout << f[n] << endl;
	
	return 0;
}

