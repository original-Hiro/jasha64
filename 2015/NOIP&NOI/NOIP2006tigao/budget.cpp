#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

ifstream cin("budget.in");
ofstream cout("budget.out");
int f[32007];
struct ItemT
{
	int Value, Importance, Belong;
	vector<int> Belonging;
	
	ItemT() {Value = Importance = Belong = 0; Belonging.clear();}
} Item[67];

int main()
{
	int MoneyN, ItemN;
	int i, j, k, V, P, V1, P1, V2, P2;
	
	cin >> MoneyN >> ItemN;
	for (i = 1; i <= ItemN; i++)
	{
		cin >> Item[i].Value >> Item[i].Importance >> Item[i].Belong;
		if (Item[i].Belong) Item[Item[i].Belong].Belonging.push_back(i);
	}
	
	for (i = 1; i <= ItemN; i++)
	{
		if (Item[i].Belong) continue;
		V = Item[i].Value;
		P = Item[i].Importance;
		Item[i].Belonging.resize(2, 0);
		V1 = Item[Item[i].Belonging[0]].Value;
		P1 = Item[Item[i].Belonging[0]].Importance;
		V2 = Item[Item[i].Belonging[1]].Value;
		P2 = Item[Item[i].Belonging[1]].Importance;
		for (j = MoneyN; j >= V; j -= 10)
		{
			f[j] = max(f[j], f[j - V] + V * P);
			if (j >= V + V1) f[j] = max(f[j], f[j - V - V1] + V * P + V1 * P1);
			if (j >= V + V2) f[j] = max(f[j], f[j - V - V2] + V * P + V2 * P2);
			if (j >= V + V1 + V2) f[j] = max(f[j], f[j - V - V1 - V2] + V * P + V1 * P1 + V2 * P2);
		}
	}
	
	cout << f[MoneyN] << endl;
	
	return 0;
}

