#include<iostream>
#include<string>
#include <cstring>
using namespace std;
int dp[1002][1002];
int max(int a,int b)
{
  if(a>b)
  return a;
  else
  return b;
}
int lcs(string s1,string s2)
{
  int a = s1.length();
  int b= s2.length();
  if(dp[a][b]!=-1)
  return dp[a][b];
  if(a==0||b==0)
  {
    dp[a][b] = 0;
    return 0;
  }
  else if(s1[0]==s2[0])
  {
    dp[a][b] = 1+lcs(s1.substr(1),s2.substr(1));
    return dp[a][b];
  }
  else{
    int a = lcs(s1.substr(1),s2);
    int b = lcs(s1,s2.substr(1));
    int c = lcs(s1.substr(1),s2.substr(1));
    dp[a][b]=max(a,max(b,c));
    return dp[a][b];
  }
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