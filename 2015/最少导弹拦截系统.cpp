#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> a, f;

int main()
{
	int n;
	int i, j;
	
	while (cin >> n)
	{
		a.clear();
		f.clear(); 
		a.resize(n);
		f.resize(n);
		
		for (i = 0; i < n; i++) cin >> a[i];
		
		fill(f.begin(), f.end(), 1);
		for (i = 1; i < n; i++)
			for (j = 0; j < i; j++)
				if (a[i] > a[j]) f[i] = max(f[i], f[j] + 1);
			
		cout << *max_element(f.begin(), f.end()) << endl;
	}
	
	return 0;
}

