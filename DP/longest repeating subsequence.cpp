#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string LRS(string str,int n)
{
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
                if(str[i-1]==str[j-1]&&i!=j)
                dp[i][j] = dp[i-1][j-1]+1;
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
        }
    }
    int p=0,q=0;
    string str2 = "";
    if(dp[n-1][n]>dp[n][n-1])
    {
        p = n-1;
        q = n;
    }
    else
    {
        p = n;
        q = n-1;
    }
    while(p>0&&q>0)
    {
        if(str[p-1]==str[q-1]&&p!=q)
        {
            str2+=str[p-1];
            p-=1;
            q-=1;
        }
        else
        {
            if(dp[p][q-1]>dp[p-1][q])
            {
                q-=1;
            }
            else
            p-=1;
        }
    }
    reverse(str2.begin(),str2.end());
    return str2;
}
int main()
{
    cout<<LRS("AABEBCDD",8);
    return 0;
}