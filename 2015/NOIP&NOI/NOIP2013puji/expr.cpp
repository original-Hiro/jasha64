#include <fstream>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

ifstream cin("expr.in");
ofstream cout("expr.out");
const int MOD = 10000;
stack<int> s;
stack<char> c;

int main()
{
    int i, cache, ans = 0;
    char cc;
    string str;
	string a;
    
    cin >> str;
    a = str;
    for (i = 0; i < a.size(); i++)
        if (!isdigit(a[i])) a[i] = ' ';
    istringstream ss(a);
    while (ss >> cache) s.push(cache);
    ss.clear();
    a = str;
    for (i = 0; i < a.size(); i++)
    	if (isdigit(a[i])) a[i] = ' ';
    ss.str(a);
    while (ss >> cc) c.push(cc);
    ss.clear();
    
    cache = s.top();
    s.pop();
    while (!c.empty())
    {
        if (c.top() == '*')
        {
            cache *= s.top() % MOD;
            cache %= MOD;
        }
        else if (c.top() == '+')
        {
            ans += cache % MOD;
            ans %= MOD;
            cache = s.top();
        }
        s.pop();
        c.pop();
    }
	ans += cache % MOD;
	ans %= MOD;
	
    cout << ans << endl;
		
    return 0;
}

