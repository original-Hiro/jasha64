#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int N = 100001;
bool f[N]; //is_prime
vector<int> a;

void Get_Prime()
{
    fill(f, f+N, 1);
    f[0] = f[1] = 0;
    for (int i = 2; i < N; i++)
	if (f[i])
	    for (int j = 2; j*i < N; j++) f[j*i] = 0;
}
bool Test(const int x)
{
    int cc = 0;
    for (int i = 0; i < a.size(); i++)
    {
		if (cc + a[i] > x) return false;
		cc += a[i];
		if (cc == x) cc = 0;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    Get_Prime();
    
    int kase;
    cin >> kase; cin.ignore(INT_MAX, '\n');
    istringstream ss;
    while (kase--)
    {
		string s;
		getline(cin, s);
	        int tot_len = 0;
		a.clear(); ss.clear(); ss.str(s);
		while (ss >> s) {tot_len += s.size()+1; a.push_back(s.size()+1);}
	
		bool sol = 0;
		for (int i = 2; i < N; i++)
		    if (f[i] && tot_len % i == 0 && Test(tot_len / i)) {cout << "YES" << endl; sol = 1; break;}
		if (!sol) cout << "NO" << endl;
    }
    
    return 0;
}

