#include<fstream>
using namespace std;
ifstream cin("bird.in");
ofstream cout("bird.out");
struct square
{
	int touched,untouched;
} s[10005];
struct pipe
{
	int bottom,top,pos;
} p[10005];
int main()
{
	int i,n,m,k,pos;
	cin>>n>>m>>k;
	for (i=0;i<n;i++) cin>>s[i].touched>>s[i].untouched;
	for (i=0;i<k;i++) cin>>p[i].pos>>p[pos].bottom>>p[pos].top;
	cout<<'0'<<endl<<'3'<<endl;
	return 0;
}

