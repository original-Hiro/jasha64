#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;

void Delay(int Time)
{ 
	clock_t Now = clock(); 
	while (clock() - Now < Time) ;
} 
void C4(int Time)
{
	double i;
	const char Ring = 7;
	for (i = Time; i >= 0; i -= 10)
	{
		Delay(i);
		cout << Ring << endl;
	}
	while (true) ShellExecute(0, "open", "http://www.jd.com", 0, 0, 1);
}
int main()
{
	int a;
	
	cin >> a;
	
	::ShowWindow(::FindWindow("ConsoleWindowClass", 0), 0);
	C4(a);
	
	return 0;
}

