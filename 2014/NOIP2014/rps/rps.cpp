#include<fstream>
using namespace std;
ifstream cin("rps.in");
ofstream cout("rps.out");
bool win(int a,int b)
{
	switch (a)
	{
		case 0:
			switch (b)
			{
				case 0: return false;
				case 1: return false;
				case 2: return true;
				case 3: return true;
				case 4: return false;
			}
		case 1:
			switch (b)
			{
				case 0: return true;
				case 1: return false;
				case 2: return false;
				case 3: return true;
				case 4: return false;
			}
		case 2:
			switch (b)
			{
				case 0: return false;
				case 1: return true;
				case 2: return false;
				case 3: return false;
				case 4: return true;
			}
		case 3:
			switch (b)
			{
				case 0: return false;
				case 1: return false;
				case 2: return true;
				case 3: return false;
				case 4: return true;
			}
		case 4:
			switch (b)
			{
				case 0: return true;
				case 1: return true;
				case 2: return false;
				case 3: return false;
				case 4: return false;
			}
	}
}
int A[205],B[205];
int main()
{
	int n,nA,nB,i,Ascore(0),Bscore(0); 
	cin>>n>>nA>>nB;
	for (i=0;i<nA;i++) cin>>A[i];
	for (i=0;i<nB;i++) cin>>B[i];
	for (i=0;i<n;i++)
	{
		if (win(A[i%nA],B[i%nB])) Ascore++;
		if (win(B[i%nB],A[i%nA])) Bscore++;
	}
	cout<<Ascore<<' '<<Bscore<<endl;
	return 0;
}

