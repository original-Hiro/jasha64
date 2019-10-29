#include<iostream>
using namespace std;
struct rec
{
    int width,height;
};
rec r[100]; 
int main()
{
    int n,a,j;
    cin>>n;
    for (int i=0;i<n;i++) cin>>r[i].width>>r[i].height;
    cin>>a;
    int minh(1000000000),w;
    for (int i=0;i<n;i++)
    {
        for (w=0,j=i;j<n&&w<a&&r[j].height<=r[i].height;j++)
            w+=r[j].width;
        for (j=i-1;j>=0&&w<a&&r[j].height<=r[i].height;j--)
            w+=r[j].width;
        if (w>=a&&r[i].height<minh)
            minh=r[i].height;
    }
    cout<<minh+a<<endl;
    system("pause");
    return 0;
}
