#include<bits/stdc++.h>
using namespace std;
int dp[501][501];
int ispallindrome(string s,int i,int j)
{
    while(i<j)
      if(s[i++]!=s[j--])
          return 0;
      
     return 1;
}
int solve(string &str,int i,int j)
{
    if(dp[i][j]!=-1)
    return dp[i][j];
    if(i>=j||ispallindrome(str,i,j))
    return 0;
    int mn = INT_MAX;
        for(int k = i;k<j;k++)
        {
            int temp = solve(str,i,k) + solve(str,k+1,j) + 1;
            mn = min(mn,temp);
        }
        dp[i][j] = mn;
        return mn;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    string str;
    str = "aaabba";
    int l = str.length();
    cout<<solve(str,0,l-1);
    return 0;
}