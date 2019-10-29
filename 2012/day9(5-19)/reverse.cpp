//NOIP2011 第1题 
#include<fstream> // file stream
using namespace std;
int main()
{
    ifstream cin("reverse.in");
    ofstream cout("reverse.out");
    int n,x;
    cin>>n;
    if (n<0) { cout<<"-"; n=-n; }  //如果是负数，输出负号 
    x=0;
    while (n>0)
    {
        x=x*10+n%10;
        n/=10;
    } 
    cout<<x<<endl;
    return 0;
}
