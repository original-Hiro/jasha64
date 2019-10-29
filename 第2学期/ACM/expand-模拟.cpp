#include <iostream>
#include <string>
#include <cctype>
using namespace std;

inline bool Expansible(char a, char b)
{
	if (isalpha(a) && isalpha(b)) return a < b;
	if (isdigit(a) && isdigit(b)) return a < b;
	return false;
}

int main()
{
	int p1, p2, p3;
	string s;
	
	cin >> p1 >> p2 >> p3 >> s;
	
	int siz = s.size();
	if (siz > 1) cout << s[0];
	for (int i = 1; i < siz-1; i++)
		if (s[i] == '-')
		{
			if (!Expansible(s[i-1], s[i+1])) {cout << '-'; continue;}
			if (p3 == 1)
			{
				for (char j = s[i-1]+1; j < s[i+1]; j++)
					for (int k = 0; k < p2; k++)
						if (p1 == 3) cout << '*';
						else if (p1 == 1) cout << j;
						else cout << (char)toupper(j);
			}
			else {
				for (char j = s[i+1]-1; j > s[i-1]; j--)
					for (int k = 0; k < p2; k++)
						if (p1 == 3) cout << '*';
						else if (p1 == 1) cout << j;
						else cout << (char)toupper(j);
			}
		}
		else cout << s[i];
	cout << s[siz-1] << endl;
	
	return 0;
}

