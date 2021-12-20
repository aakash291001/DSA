#include<iostream>
#include<limits.h>
#include<cmath>
using namespace std;
int minCount(int n)
{
    int dp[1002];
    for(int i=0;i<n+1;i++)
    {
        dp[i]=-1;
    }
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for(int i=4;i<n+1;i++)
    {
        int p = sqrt(i);
        int min = INT_MAX;
        for(int j=1;j<=p;j++)
        {
            int s = dp[i-j*j]+1;
            if(s<min)
            min = s;
        }
        dp[i]=min;
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    cout<<minCount(n);
    return 0;
}