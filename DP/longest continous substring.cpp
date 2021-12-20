#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int dp[1002][1002];
int lcs(string s1,string s2)
{
  int dp[s1.length()+1][s2.length()+1];
  memset(dp,-1,sizeof(dp));
  int max=-1;
  for(int i=0;i<=s1.length();i++)
  {
    for(int j=0;j<=s2.length();j++)
    {
      if(i==0||j==0)
      dp[i][j] = 0;
      else
      {
        if(s1[i]==s2[j])
        {
          dp[i][j] = 1+dp[i-1][j-1];
        }
        else
        {
          dp[i][j]=0;
        }
      }
      if(max<dp[i][j])
      max = dp[i][j];
    }
  }
  return max;
}
int main()
{
  memset(dp,-1,sizeof(dp));
  string s1,s2;
  cin>>s1;
  cin>>s2;
  cout<<lcs(s1,s2);
  return 0;
}