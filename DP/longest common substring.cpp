#include<iostream>
using namespace std;
void LCS(string x,string y,int m,int n,int &l,int &max)
{
    if(m==0||n==0)
    l=0;
    else
    {
        if(x[m-1]==y[n-1])
        {
            l+=1;
            if(max<l)
            max = l;
            LCS(x,y,m-1,n-1,l,max);
        }
        else
        {
            l=0;
            LCS(x,y,m-1,n,l,max);
            LCS(x,y,m,n-1,l,max);
        }
    }
}
int LCS2(string x,string y,int m,int n)
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
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=0;
            }
        }
    }
    int maximum=INT_MIN;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(maximum<dp[i][j])
            maximum=dp[i][j];
        }
    }
    return maximum;
}
int main()
{
    string x,y;
    x = "zxabcdezy";
    y = "yzabcdezx";
    int l=0;
    int max = 0;
    LCS(x,y,9,9,l,max);
    cout<<max;
    return 0;
}