#include<iostream>
using namespace std;
int main()
{
    int n,h,m,s;
    cin>>n;
    h=n/3600;
    m=n/60%60;
    s=n%60;
    if (h<10&&m>=10&&s>=10) cout<<'0'<<h<<':'<<m<<':'<<s<<endl;
    else if (h<10&&m>=10&&s<10) cout<<'0'<<h<<':'<<m<<':'<<'0'<<s<<endl;
    else if (h<10&&m<10&&s>=10) cout<<'0'<<h<<':'<<'0'<<m<<':'<<s<<endl;
    else if (h<10&&m<10&&s<10) cout<<'0'<<h<<':'<<'0'<<m<<':'<<'0'<<s<<endl;
    else if (h>=10&&m>=10&&s>=10) cout<<h<<':'<<m<<':'<<s<<endl;
    else if (h>=10&&m<10&&s>=10) cout<<h<<':'<<m<<':'<<s<<endl;
    else if (h>=10&&m>=10&&s<10) cout<<h<<':'<<m<<':'<<'0'<<s<<endl;
    else if (h>=10&&m<10&&s<10) cout<<h<<':'<<'0'<<':'<<'0'<<s<<endl;
    return 0;
}
