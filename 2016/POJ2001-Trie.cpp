#include <cstdio>
#include <cstring>
using namespace std;

const int N = 20007, SIGMA_SIZE = 26;
int T;
char c[N][27];
inline int idx(char c) {return c - 'a';}
struct _
{
	bool t[N];
	int ch[N][SIGMA_SIZE], cnt[N];
	int Top;
	
	void Insert()
	{
		int v = 0, len = strlen(c[T]);
		for (int i = 0; i < len; i++)
		{
			int x = idx(c[T][i]);
			if (!ch[v][x]) ch[v][x] = ++Top;
			++cnt[v = ch[v][x]];
		}
		t[v] = true;
	}
	void Print(int T)
	{
		int v = 0, len = strlen(c[T]);
		for (int i = 0; i < len; i++)
		{
			printf("%c", c[T][i]);
			int x = idx(c[T][i]);
			v = ch[v][x];
			if (cnt[v] == 1) break;
		}
		printf("\n");
	}
} Trie;

int main()
{
	while (scanf("%s", c[++T]) == 1) Trie.Insert();
	
	for (int i = 1; i < T; i++) {printf("%s ", c[i]); Trie.Print(i);}
	
	return 0;
}

