#include<fstream>
#include<algorithm>
using namespace std;
int a[200001];
int main()
{
    ifstream cin("count.in");
    ofstream cout("count.out");
    int n,i;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int x,y;
    x=a[0];
    y=1;
    for (i=1;i<n;i++)
        if (a[i]==x) y++;
        else {
            cout<<x<<" "<<y<<endl;
            x=a[i];
            y=1;
        }
    cout<<x<<" "<<y<<endl;
    return 0;
}
    
            
