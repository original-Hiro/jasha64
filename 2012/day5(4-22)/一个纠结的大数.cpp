#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    double s;
    s=0;
    n=0;
    while (s<=10)
    {
        n++;
        s+=1.0/n;
    }
    cout<<n<<endl;
    system("pause");
    return 0;
}
