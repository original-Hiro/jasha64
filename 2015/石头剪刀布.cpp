#include <iostream>
using namespace std;

inline int Res(int a, int b)
{
	switch (a)
	{
		case 'R':
			switch (b)
			{
				case 'R': return 0;
				case 'P': return -1;
				case 'S': return 1;
			}
		case 'P':
			switch (b)
			{
				case 'R': return 1;
				case 'P': return 0;
				case 'S': return -1;
			}
		case 'S':
			switch (b)
			{
				case 'R': return -1;
				case 'P': return 1;
				case 'S': return 0;
			}
	}
}

int main()
{
	int T, n, A, B, c;
	char a, b;
	
	cin >> T;
	while (T--)
	{
		cin >> n;
		A = B = 0;
		while (n--)
		{
			cin >> a >> b;
			c = Res(a, b);
			if (c > 0) ++A;
			else if (c < 0) ++B;
		}
		if (A > B) cout << "Player 1" << endl;
		else if (A < B) cout << "Player 2" << endl;
		else cout << "TIE" << endl;
	}
	
	return 0;
}

