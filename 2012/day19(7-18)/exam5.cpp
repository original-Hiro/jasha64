#include<iostream>
using namespace std;
void move(char x,char y)
{
    cout<<x<<"->"<<y<<" ";
}
void hanoi(int n,char a,char b,char c)
{
    if (n==1) move(a,c);
    else{
        hanoi(n-1,a,c,b);
        move(a,c);
        hanoi(n-1,b,a,c);
    }
} 
        
int main()
{
    int n;
    while (cin>>n)
    {
        hanoi(n,'A','B','C');
        cout<<endl;
    }
    return 0;
}
