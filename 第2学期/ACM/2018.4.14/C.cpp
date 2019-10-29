#include <iostream>
#include <algorithm>
using namespace std;

inline int min(int a, int b, int c) {return min(min(a, b), c);}

int main()
{
    ios::sync_with_stdio(false);
    int kase;
    cin >> kase;
    while (kase--)
    {
		int a, b, c;
		cin >> a >> b >> c;
		
		int d = min(a, b, c);
		if (a == d) cout << "First" << endl;
		else if (b == d) cout << "Second" << endl;
		else cout << "Third" << endl;
    }
    
    return 0;
}

