#include <iostream>
using namespace std;

const int N = 200001;
int a[N];

int main()
{
    int n;

    cin >> n;
    for (int i = 0, x; i < n; i++) {cin >> x; a[x]++;}

    int Res = 0;
    for (int i = 1; i < N; i++)
    {
	if (a[i] % 2 == 1) a[i]--;
	Res += a[i];
    }
    Res /= 4;
    cout << Res << endl;
    
    return 0;
}
