#include <iostream>
using namespace std;

inline int Lowbit(int x) {return x & -x;}

int main()
{
	ios::sync_with_stdio(false);
	
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;

		int Res = 0;
		for (int i = n ^ (n-1); i > 0; i -= Lowbit(i)) ++Res;

		cout << Res << endl;
	}
	
	return 0;
}


