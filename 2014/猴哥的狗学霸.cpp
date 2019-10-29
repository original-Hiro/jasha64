#include<iostream>
#include<algorithm>
using namespace std;
struct dog
{
    int mt,tt;
};
int main()
{
    int N(0),n,i,j,w(0),t(0);
    dog dog[1005],dog1;
    cin>>n;
    for (i=0;i<n;i++)
        cin>>dog[i].tt>>dog[i].mt;
    for (i=1;i<n;i++)
        if (dog[i].mt>dog[i-1].mt)
        {
           dog1.mt=dog[i].tt;
           dog[i].mt=dog[i-1].tt;
           dog[i-1].mt=dog1.mt;
           dog1.tt=dog[i].tt;
           dog[i].tt=dog[i-1].tt;
           dog[i-1].tt=dog1.tt;
        }
    for (i=0;i<n;i++)
        {
            w+=dog[i].tt;         
            t=max(dog[i].mt+w,t);     
        }                     
    cout<<t<<endl;
    return 0;
}
