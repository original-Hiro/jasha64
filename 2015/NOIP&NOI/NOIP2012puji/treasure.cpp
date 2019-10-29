#include <fstream>
using namespace std;

ifstream cin("treasure.in");
ofstream cout("treasure.out");
const int N = 10007, MOD = 20123;
int FloorN, RoomN, Number[N][107], Pos;
bool HaveStair[N][107];
int Res, RoomNum[N][107], size[N];

int main()
{
	int i, j, cache;
	
	cin >> FloorN >> RoomN;
	for (i = 1; i <= FloorN; i++)
		for (j = 0; j < RoomN; j++)
		{
			cin >> HaveStair[i][j] >> Number[i][j];
			if (HaveStair[i][j]) RoomNum[i][size[i]++] = j;
		}
	cin >> Pos;
	
	for (i = 1; i <= FloorN; i++)
	{
		cache = 0;
		Res = (Res + Number[i][Pos]) % MOD;
		for (j = Pos; j < RoomN; j++)
			if (HaveStair[i][j]) cache++;
		Pos = RoomNum[i][(Number[i][Pos] - cache - 1 + size[i]) % size[i]];
	}
	
	cout << Res << endl;
		
	return 0;
}

