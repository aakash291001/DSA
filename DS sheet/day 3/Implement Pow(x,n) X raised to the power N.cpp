#include<bits/stdc++.h>
using namespace std;
void power(double n,int x)
{
    double n1 = n;
    long x1 = x;
    double ans = 1;
    if(x1<0)
    {
        x1 = x1*(-1);
    }
    while(x1>0)
    {
        if(x1%2==0)
        {
            n1 = n1*n1;
            x1 = x1/2;
        }
        else
        {
           ans*=n1;
            x1=x1-1;
        }
    }
    if(x<0)
    {
        double oe = 1;
        double ans2 = oe/ans;
        cout<<ans2;
    }
    else
    cout<<ans;
}
int main()
{
    float x = 2.1000;
    power(x,-3);
    return 0;
}