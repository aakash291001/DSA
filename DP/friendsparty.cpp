#include<iostream>
#include<vector>
using namespace std;
int fripry(int n)
{
  vector<int> dp(n+1,0);
  dp[1]=1;
  dp[2]=2;
  for(int i=3;i<=n;i++)
  {
    dp[i]=dp[i-1]+(i-1)*dp[i-2];
  }
  return dp[n];
}
int main()
{
  cout<<"enter no. of friends\n";
  int n;
  cin>>n;
  cout<<"\nNo. of ways are="<<fripry(n);
  return 0;
}