//SPOJ - a needle in the haystack
//BF(0.34s)
#include <list>
#include <cstdio>
#include <iterator>
#include <cctype>
using namespace std;

bool Read(char& c)
{
	c = getchar();
	while (!isalpha(c) && c != '\n') c = getchar();
	return c != '\n';
}

int len;
char* p; //pattern
list<char> t; //text
bool BF()
{
	int j = 0;
	list<char>::iterator i = t.begin();
	while (j < len)
	{
		if (*i == p[j]) {i++; j++;}
		else return 0;
	}
	return 1;
}

int main()
{
	bool First = 1;
	while (scanf("%d", &len) == 1)
	{
		if (!First) printf("\n");
		else First = 0;
		t.clear();
		
		p = new char [len+1];
		scanf("%s", p);
		while (getchar() != '\n') ;
		char c;
		while (t.size() < len && Read(c)) t.push_back(c);
		if (t.size() < len) {delete[] p; continue;}
		
		int pos = 0;
		while (true)
		{
			if (BF()) printf("%d\n", pos);
			pos++;
			if (!Read(c)) break;
			t.erase(t.begin()); t.push_back(c);
		}
		
		delete[] p;
	}
	
	return 0;
}

