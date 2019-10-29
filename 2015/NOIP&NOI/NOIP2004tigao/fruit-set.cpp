#include<fstream>
#include<set>
#include<iterator>
using namespace std;
ifstream cin("fruit.in");
ofstream cout("fruit.out");
multiset<int> a;
multiset<int>::iterator I;
int main()
{
    int n,i,cache,ans(0);
    cin>>n;
    for (i=0;i<n;i++)
    {
        cin>>cache;
        a.insert(cache);
    }
    if (n==1)
    {
        cout<<'0'<<endl;
        return 0;
    }
    if (n==2)
    {
        cout<<*a.begin()+*a.end()<<endl;
        return 0;
    }
    for (I=a.begin();I!=a.end();)
    {
        cache=*I+*(++I);
        ans+=cache;
        a.erase(a.begin());
        a.erase(a.begin());
        a.insert(cache);
        if (I!=a.begin()) I=a.begin();
        if (a.size()<=1) break;
    }
    cout<<ans<<endl;
    return 0;
}
 

