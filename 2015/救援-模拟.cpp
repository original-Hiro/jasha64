#include <iostream>
#include <cmath> 
using namespace std;

int main()
{
	int n, PeopleN;
	double x, y, Res = 0;
	
	cin >> n;
	while (n--) 
	{
		cin >> x >> y >> PeopleN;
		Res += hypot(x, y) * 2 / 50.0 + PeopleN * 1.5;
	}
	
	cout << (int)ceil(Res) << endl;
	
	return 0;
} 

