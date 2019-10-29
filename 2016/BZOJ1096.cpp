#include <iostream>
#include <cstdio>
#include <cctype>
using namespace std;
 
const int N = 1000007;
int s[N], c[N], q[N], front, rear = 1;
long long p[N], sp[N], f[N];

template <typename T>
inline T Read()
{
	T r = 0;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) {r = r * 10 + c - '0'; c = getchar();}
	return r;
}
inline double slop(int a, int b) {return (f[b] + sp[b] - f[a] - sp[a]) / (double)(p[b] - p[a]);}
 
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
	{
		s[i] = Read<int>(); p[i] = Read<long long>(); c[i] = Read<int>();
		sp[i] = sp[i - 1] + s[i] * p[i];
	}
    for (int i = 2; i <= n; i++) p[i] += p[i - 1];
    
    for (int i = 1; i <= n; i++)
    {
        while (rear > front + 1 && slop(q[front], q[front + 1]) < s[i]) ++front;
        int j = q[front];
        f[i] = f[j] + s[i] * (p[i - 1] - p[j]) - (sp[i - 1] - sp[j]) + c[i];
		while (rear > front + 1 && slop(q[rear - 1], i) < slop(q[rear - 2], q[rear - 1])) --rear;
        q[rear++] = i;
    }
     
    cout << f[n] << endl;
     
    return 0;
}

