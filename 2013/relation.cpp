#include<iostream>
#include<cstdio>
using namespace std;
int father[1000008];
int f(int x)
{
    while (father[x]!=x) x=father[x];
    return x;
}
int main()
{
    freopen("relation.in","r",stdin); //fstream cin("relation.in");
    freopen("relation.out","w",stdout);//ofstream cout("relation.out");
    int n,m,x,y,k1,k2,q;
    cin>>n>>m;
    for (int i=1;i<=n;i++) father[i]=i;
    for (int i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);  //cin>>x>>y;
        k1=f(x);
        k2=f(y);
        if (k1!=k2) father[k2]=father[x]=father[y]=k1;
    }
    cin>>q;
    for (int i=0;i<q;i++)
    {
        scanf("%d%d",&x,&y);  //cin>>x>>y;
        if (f(x)==f(y)) printf("Yes\n"); //cout<<"Yes"<<endl;
        else printf("No\n"); //cout<<"No"<<endl;
    }
    //system("pause");
    return 0;
}
        
