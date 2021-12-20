#include<iostream>
using namespace std;
int nBalTree(int n)
{
    int dp[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=-1;
    }
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;
    for(int i=3;i<=n;i++)
    {
        int a = dp[i-1];
        int b = dp[i-2];
        dp[i] = a*a + a*b*2;
    }
    return dp[n];
    // if(n==0||n==1)
    // return n;
    // else if(n==2)
    // return 3;
    // else
    // {
    //     int a = nBalTree(n-1);
    //     int b = nBalTree(n-2);
    //     return a*a + a*b*2;
    // }
}
int main()
{
    int n;
    cin>>n;
    cout<<nBalTree(n);
    return 0;
}