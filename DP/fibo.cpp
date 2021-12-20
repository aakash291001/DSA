#include<iostream>
#include<vector>
using namespace std;
int fibdp(int n,vector<int> &dp)
{
  if(n==1||n==0)
  return n;
  if(dp[n]!=-1)
  return dp[n];
  int ans;
  ans = fibdp(n-1,dp)+fibdp(n-2,dp);
  dp[n]=ans;
  return ans;
}
int main()
{
  int n;
  cout<<"Enter no. of element\n";
  cin>>n;
  vector<int> dp(n+1,-1);
  int p;
  p = fibdp(n,dp);
  cout<<"\nlast term is "<<p;
  return 0;
}