#include <fstream>
#include <cstring>
using namespace std;

ifstream cin("queue.in");
ofstream cout("queue.out");

const int N = 200007, K = 1000007;
const long long MOD = 998244353;
char a[N], s[K];
int Next[N];

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	bool Spc1 = true; //ȫΪ1 
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {cin >> a[i]; Spc1 &= (a[i] == 1);}
	if (n <= 1000)
	{
		while (m--)
		{
			int argv, d, e, k;
			
			cin >> argv;
			if (argv == 1)
			{
				cin >> d >> e;
				Next[d] = e;
			}
			else if (argv == 2)
			{
				cin >> d;
				Next[d] = 0;
			}
			else {
				cin >> s >> k;
				long long Res = 1;
				for (int S = 0; S + k <= strlen(s); S++)
				{
					int c = 0;
					for (int i = 1; i <= n; i++)
					{
						int p = i;
						int j;
						for (j = 0; j < k; j++)
						{
							if (!p || a[p] != s[S + j]) break;
							p = Next[p];
						}
						if (j >= k) ++c;
					}
					Res = (Res * c) % MOD;
					if (c == 0) break;
				}
				cout << Res << endl;
			}
		}
	}
	else if (Spc1)
	{
		
	}
	else {
		int c[58] = {};
		for (int i = 1; i <= n; i++) ++c[a[i]];
		while (m--)
		{
			int argv, d, e, k;
			
			cin >> argv;
			if (argv == 1) {cin >> d >> e; continue;}
			else if (argv == 2) {cin >> d; continue;}
			else {
				cin >> s >> k;
				long long Res = 1;
				for (int i = 0; i < strlen(s); i++)
				{
					Res = (Res * c[s[i]]) % MOD;
					if (c[s[i]] == 0) break;
				}
				cout << Res << endl;
			}
		}
	} //k=1
	
	return 0;
}

