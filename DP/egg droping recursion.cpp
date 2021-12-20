#include<bits/stdc++.h>
using namespace std;
int maxi(int a,int b)
{
    if(a>b)
    return a;
    else
    return b;
}
int min(int a,int b)
{
    if(a>b)
    return b;
    else
    return a;
}
int solve(int e,int f)
{
    if(f==0||f==1)
    {
        return f;
    }
    if(e==1)
    return f;
    int mn = INT_MAX;
    for(int k = 1;k<=f;k++)
    {
        int ans = 1+maxi(solve(e,f-k),solve(e-1,k-1));
        
        mn = min(mn,ans);
    }
    return mn;
}
int main()
{
    cout<<solve(3,7);
    return 0;
}