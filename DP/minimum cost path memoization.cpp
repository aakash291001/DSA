#include<iostream>
#include <bits/stdc++.h>
#include<limits.h>
using namespace std;
int dp[1002][1002];
int min(int a,int b)
{
    if(a<b)
    return a;
    else
    return b;
}
int minCost(int **input,int r,int c,int i,int j)
{
    if(i==r-1&&j==c-1)
    {
        dp[i][j] = input[i][j];
        return input[i][j];
    }
    if(i>=r||j>=c)
    {
        dp[i][j] = INT_MAX;
        return INT_MAX;
    }
    if(dp[i][j]!=-1)
    return dp[i][j];
    else
    {
        int a = minCost(input,r,c,i+1,j);
        int b = minCost(input,r,c,i,j+1);
        int c = minCost(input,r,c,i+1,j+1);
        int ans = min(a,min(b,c))+input[i][j];
        dp[i][j] = ans;
        return dp[i][j];
    }
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int r,c;
    cin>>r>>c;
    int **input = new int*[r];
    for(int i=0;i<r;i++)
    {
        input[i] = new int[c];
        for(int j=0;j<c;j++)
        {
            cin>>input[i][j];
        }
    }
    int ans = minCost(input,r,c,0,0);
    cout<<ans;
    return 0;
}