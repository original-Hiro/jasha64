#include<iostream>
using namespace std;
int main()
{
    int s;
    cin>>s;
    if (s>=110) cout<<"A"<<endl;
    else if (s>=105) cout<<"B"<<endl;
         else if (s>=100) cout<<"C"<<endl;
              else if (s>=95) cout<<"D"<<endl;
                   else if (s>=90) cout<<"E"<<endl;
                        else cout<<"F"<<endl;
    system("pause");
    return 0;
}
