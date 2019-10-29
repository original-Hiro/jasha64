#include "RTreeUsage.h"
#include <vector>
using namespace std;

bool SearchCallback(int id, vector<int>& cont)
{
	cont.emplace_back(id);
	return true;
}

