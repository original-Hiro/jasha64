#include <iostream>
#include <algorithm>
#include <cstdarg>
using namespace std;

template <typename T>
inline T Max(int Num, const T& a, ...)
{
	va_list argv;
	T c, Res = a;
	
	va_start(argv, a);
	Num--;
	while (Num--)
	{
		c = va_arg(argv, T);
		Res = max(Res, c);
	}
	va_end(argv);
	
	return Res;
}

int main()
{
	int a, b, c, d;
	
	cin >> a >> b >> c >> d;
	
	cout << Max(4, a, b, c, d) << endl;
	
	return 0;
}

