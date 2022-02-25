#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cout<<"Enter two numbers";
    cin>>a;
    cout<<"\n";
    cin>>b;
    int gcd = 1;
    for(int i =2;i<=a&&i<=b;i++)
    {
        if(a%i==0&&b%i==0)
        gcd=i;
    }
    cout<<gcd;
    return 0;
}
