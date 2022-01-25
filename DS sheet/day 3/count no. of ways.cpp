#include<bits/stdc++.h>
using namespace std;
int countWays(int r,int c,int i,int j)
{
    if(i==r-1&&j==c-1)
    {
        return 1;
    }
    else if(i==r-1)
    {
        return countWays(r,c,i,j+1);
    }
    else if(j==c-1)
    {
        return countWays(r,c,i+1,j);
    }
    else
    {
        return countWays(r,c,i+1,j)+countWays(r,c,i,j+1);
    }
}
int countWays2(int r,int c)
{
	int dp[r][c];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(i==0&&j==0)
			dp[i][j]=1;
			else if(i==0)
			dp[i][j]=1;
			else if(j==0)
			dp[i][j]=1;
			else
			{
				dp[i][j] = dp[i][j-1]+dp[i-1][j];
			}	
		}
	}
	return dp[r-1][c-1];
}
int countWays3(int r,int c)
{
	int N = r+c-2;
	int R = r-1;
	int ans=1;
	for(int i=1;i<=R;i++)
	{
		ans = ans*(N-R+i)/i;
	}
	return ans;
}
int main()
{
    cout<<countWays3(3,7);
    return 0;
}