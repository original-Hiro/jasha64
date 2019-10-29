#include<fstream>
#include<algorithm>
using namespace std;
const int N(10005);
bool f[N];
int main()
{
    ifstream cin("tree.in");
    ofstream cout("tree.out");
    int L,m,begin,end;
    fill(f,f+N,true);
    cin>>L>>m;
    for (int i=0;i<m;i++)
    {
        cin>>begin>>end;
        for (int j=begin;j<=end;j++)
            f[j]=false;
    }
    int sum(0);
    for (int i=0;i<=L;i++)
        if (f[i]) sum++;
    cout<<sum<<endl;
    return 0;
}
