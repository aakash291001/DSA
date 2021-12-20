#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string SCS(string str1,string str2,int m,int n)
{
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        dp[i][0]=0;
    }
    for(int i=0;i<=n;i++)
    {
        dp[0][i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(str1[i-1]==str2[j-1])
            dp[i][j]=dp[i-1][j-1]+1;
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int i = m;
    int j = n;
    string str3="";
    while(j>0&&i>0)
    {
        if(str1[i-1]==str2[j-1])
        {
            str3+=str1[i-1];
            i-=1;
            j-=1;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
            {
                str3+=str1[i-1];  
                i-=1;
            }
            else
            {
                str3+=str2[j-1];
                j-=1;
            }
        }
    }
    while(i>0)
    {
        str3+=str1[i-1];
        i-=1;
    }
    while(j>0)
    {
        str3+=str2[j-1];
        j-=1;
    }
    reverse(str3.begin(),str3.end());
    return str3;
}
int main()
{
    cout<<SCS("AGGTAB","GXTXAYB",6,7);
    return 0;
}