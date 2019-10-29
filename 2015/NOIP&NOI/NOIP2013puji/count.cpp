#include <fstream>
using namespace std;

ifstream cin("count.in");
ofstream cout("count.out");

int num (const int& a, const int& b)
{
	int c, i, sum = 0;
	for (i = 1; i <= a; i++)
	{
    	c = i;
    	while (c != 0)
    	{
    	    if (c % 10 == b) sum++;
			c /= 10;
	    }	
	}
	return sum;
}

int main()
{
	int n, x;
	cin >> n >> x;
	cout << num(n, x) << endl;
	return 0;
}

