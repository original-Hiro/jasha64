#include <iostream>
using namespace std;

int main()
{
    int a, b;

    cin >> a >> b;
    
    if (a % b != 0 || a == b) cout << -1 << endl;
    else cout << b << ' ' << a-b << endl;
	
    return 0;
}
