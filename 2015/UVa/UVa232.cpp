#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

struct square
{
	char inside;
	bool start;
	int num;
	
	square () {start = (num = 0); inside = ' ';}
} s[12][12];

int main()
{
	int r, c;
	int i, j, k, kase(0), number(1);
	char C;
	
	while ((cin >> r) && r)
	{
		cin >> c;
		for (i = 0; i <= r + 1; i++) s[i][0].inside = (s[i][c + 1].inside = '*');
		for (i = 0; i <= c + 1; i++) s[0][i].inside = (s[r + 1][i].inside = '*');
		for (i = 1; i <= r; i++)
			for (j = 1; j <= c; j++)
			{
				C = getchar();
				if (C == '\r' || C == '\n') {j--; continue;}
				s[i][j].inside = C;
			}
			
		for (i = 1; i <= r; i++)
			for (j = 1; j <= c; j++)
				if ((s[i-1][j].inside == '*' || s[i][j-1].inside == '*')
				&& s[i][j].inside != '*')
				{
					s[i][j].start = 1;
					s[i][j].num = number++;
				}
		
		if (kase) cout << endl;
		cout << "puzzle #" << ++kase << ':' << endl;
		cout << "Across" << endl;
		for (i = 1; i <= r; i++)
			for (j = 1; j <= c; j++)
				if (s[i][j].start && s[i][j-1].inside == '*')
				{
					cout << setw (3) << s[i][j].num;
					cout << '.';
					for (k = j; k <= c && s[i][k].inside != '*'; k++)
						cout << s[i][k].inside;
					cout << endl;
				}
		cout << "Down" << endl;
		for (i = 1; i <= r; i++)
			for (j = 1; j <= c; j++)
				if (s[i][j].start && s[i-1][j].inside == '*')
				{
					cout << setw (3) << s[i][j].num;
					cout << '.';
					for (k = i; k <= r && s[k][j].inside != '*'; k++)
						cout << s[k][j].inside;
					cout << endl;
				}
		
		number = 1;
		for (i = 0; i <= r + 1; i++) fill (s[i], s[i] + c + 2, square () );
	}
	
	return 0;
}

