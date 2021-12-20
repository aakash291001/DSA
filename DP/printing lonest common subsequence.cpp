#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
void LCS(string x,string y,int m,int n)
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
            if(x[i-1]==y[j-1])
            dp[i][j] = dp[i-1][j-1]+1;
            else
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int i = m,j=n;
    string s1 = "";
    while(i>0&&j>0)
    {
        if(x[i-1]==y[j-1])
        {
            s1+=x[i-1];
            i-=1;
            j-=1;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
            i-=1;
            else
            j-=1;
        }
    }
    reverse(s1.begin(), s1.end());
    cout<<s1;
}
int main()
{
    string x,y;
    x = "abcdaf";
    y = "acbcf";
    LCS(x,y,6,5);
    return 0;
}