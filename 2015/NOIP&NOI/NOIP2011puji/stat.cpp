#include <fstream>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;

ifstream cin("stat.in");
ofstream cout("stat.out");

inline void Repr(string& s)
{
	for (int i = 0; i < s.size(); i++)
		if (isupper(s[i])) s[i] = tolower(s[i]);
}

int main()
{
	int count = 0, pos = 0;
	bool mark = 0;
	string s, article, cache;
	
	getline(cin, s);
	getline(cin, article);
	Repr(s);
	Repr(article);
	
	istringstream ss(article);
	for (int i = 0; i < article.size(); i++)
		if ((i == 0 || article[i - 1] == ' ') && article[i] != ' ')
		{
			ss >> cache;
			if (cache == s)
			{
				count++;
				if (!mark)
				{
					pos = i;
					mark = 1;
				}
			}
		}
	
	if (!count) cout << -1 << endl;
	else cout << count << ' ' << pos << endl;
	
	return 0;
}

