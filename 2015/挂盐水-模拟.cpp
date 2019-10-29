#include<iostream>
using namespace std;

int main()
{
	int Vul, Sub;
	int i, j, Res;
	
	while (cin >> Vul >> Sub)
	{
		Res = 0;
		
		for (i = 1;; i++)
		{
			for (j = 0; j < i; j++)
			{
				Vul -= Sub;
				Res++;
				if (Vul <= 0)
				{
					cout << Res <<endl;
					break;
				}
			}
			if (Vul <= 0) break;
			Res++;
		}
	}
	
	return 0;
}

