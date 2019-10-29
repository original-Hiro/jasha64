#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define P_amb {cout << "Ambiguous" << endl; return 0;}
#define P_imp {cout << "Impossible" << endl; return 0;}

string s[3];
struct diff
{
    int pos, type, pt;
    //type == 0 indicates two are same, when pt indicates the one that's different
    //type == 1 indicates none is same, when pt makes no sense
};
vector<diff> v;

int main()
{
    ios::sync_with_stdio(false);
    cin >> s[0] >> s[1] >> s[2];

    //count differences
    for (int i = 0; i < s[0].size(); i++)
	if (!(s[0][i] == s[1][i] && s[0][i] == s[2][i]))
	{
	    diff d;
	    d.pos = i;
	    if (s[0][i] != s[1][i] && s[1][i] != s[2][i] && s[0][i] != s[2][i]) d.type = 1;
	    else {
		d.type = 0;
		if (s[0][i] == s[1][i]) d.pt = 2;
		else if (s[0][i] == s[2][i]) d.pt = 1;
		else d.pt = 0;
	    }
	    v.push_back(d);
	    if (v.size() > 3) P_imp;
	}
    //calc solution
    if (v.size() <= 1) P_amb;
    if (v.size() == 3)
    {
	bool u[3] = {0};
	for (int i = 0; i < 3; i++)
	{
	    if (v[i].type == 1) P_imp;
//all-diff difference is impossible under 3-difference cases
	    if (u[v[i].pt]) P_imp;
	    if (v[i].pt == 0) s[0][v[i].pos] = s[1][v[i].pos];
	    u[v[i].pt] = 1;
	}
	cout << s[0] << endl;
    }
    else {
	int typ = -1;
	for (int i = 0; i < 2; i++) typ += v[i].type;
	if (typ == 1) P_imp;
	if (typ == 0)
	{
	    if (v[0].type == 1) swap(v[0], v[1]);
	    if (v[0].pt == 0) s[0][v[0].pos] = s[1][v[0].pos];
	    if (v[0].pt != 0) s[0][v[1].pos] = s[v[0].pt][v[1].pos];
	    cout << s[0] << endl;
	}
	else {
	    if (v[0].pt == v[1].pt) P_amb;
	    for (int i = 0; i < 2; i++)
		if (v[i].pt == 0) s[0][v[i].pos] = s[1][v[i].pos];
	    cout << s[0] << endl;
	}
    }
    
    return 0;
}
