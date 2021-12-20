#include<iostream>
using namespace std;
int coinChange(int coin[],int n,int sum)
{
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
    {
        dp[i][0] = 0;
    }
    for(int i=0;i<=sum;i++)
    {
        dp[0][i] = 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j<coin[i-1])
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = max(dp[i][j-coin[i-1]]+1,dp[i-1][j]);
            }
        }
    }
    return dp[n][sum];
}
int main()
{
    int coin[] = {1,2,3};
    int sum=5;
    cout<<coinChange(coin,3,sum);
    return 0;
}