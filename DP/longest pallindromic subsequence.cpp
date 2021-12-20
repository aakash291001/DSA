#include <bits/stdc++.h>
using namespace std;
int LPS(string str,int n)
{
    string str2;
    str2 = str;
    reverse(str2.begin(), str2.end());
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(str[i-1]==str2[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else
            dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }
    }
    return dp[n][n];
}
int main()
{
    string str = "GEEKSFORGEEKS";
    cout<<LPS(str,13);
    return 0;
}
