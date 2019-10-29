#include <fstream>
using namespace std;

ifstream cin("martian.in");
ofstream cout("martian.out");
const int N = 10007;
int n, x, a[N], Count = -1;
bool v[N], d[N];

void Permutate(int Cur)
{
	if (Cur == n)
	{
		Count++;
		if (Count == x) return;
	}
	else {
		int i;
		if (!d[Cur]) {i = a[Cur]; d[Cur] = true;}
		else i = 1;
		for (; i <= n; i++)
			if (!v[i])
			{
				v[i] = true;
				a[Cur] = i;
				Permutate(Cur + 1);
				if (Count == x) return;
				v[i] = false;
			}
	}
}

int main()
{
	int i;
	
	cin >> n >> x;
	for (i = 0; i < n; i++) cin >> a[i];
	
	Permutate(0);
	
	cout << a[0];
	for (i = 1; i < n; i++) cout << ' ' << a[i];
	cout << endl;
	
	return 0;
}

