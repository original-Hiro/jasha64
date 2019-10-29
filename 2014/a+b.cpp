#include<fstream>
using namespace std;
ifstream cin("a+b.in");
ofstream cout("a+b.out");
int sum(int a,int b)
{
    return a+b;
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<sum(a,b)<<endl;
    return 0;
}
