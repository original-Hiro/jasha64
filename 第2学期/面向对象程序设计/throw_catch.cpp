#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

int main()
{
	vector<int> v;
	
	try {
		int a;
		while (cin >> a) v.push_back(a);
		if (v.empty()) throw domain_error("no valid input");
	}
	catch (domain_error e)
	{
		cout << e.what() << endl;
		return 3;
	}
	
	return 0;
}

