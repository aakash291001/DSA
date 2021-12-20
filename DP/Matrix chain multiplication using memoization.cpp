#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int solve(int A[],int i,int j)
{
    if(i>=j)
    {
        return 0;
    }
    else if(dp[i][j]!=-1)
    return dp[i][j];
    else
    {
        int mn = INT_MAX;
        for(int k=i;k<j;k++)
        {
            int temp = solve(A,i,k)+solve(A,k+1,j)+A[i-1]*A[k]*A[j];
            if(mn>temp)
            mn = temp;
        }
        dp[i][j] = mn;
        return mn;
    }
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int A[]={40,20,30,10,30};
    cout<<solve(A,1,4);
    return 0;
}