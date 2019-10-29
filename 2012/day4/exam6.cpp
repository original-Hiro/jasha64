#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    cout<<(a>(b>c?b:c)?a:(b>c?b:c))<<endl;
    system("pause");
    return 0;
}
