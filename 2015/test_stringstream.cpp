#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>
#include<cctype>
#include<iterator>
#include<set>
using namespace std;
void Convert (string &s)
{
	int i;
	for (i=0;i<s.size();i++)
	{
		if (isalpha(s[i])) s[i]=tolower(s[i]);
		else s[i]=' ';
	}
}
int main()
{
	string s,c;
	set<string> dict;
	set<string>::iterator i;
	getline(cin,s);
	Convert(s);
	stringstream a(s);
	while (a>>c) dict.insert(c);
	for (i=dict.begin();i!=dict.end();i++) cout<<*i<<endl;
	return 0;
}

