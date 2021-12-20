#include<iostream>
#include <bits/stdc++.h>
#include<limits.h>
using namespace std;
int min(int a,int b)
{
	if(a<b)
	return a;
	else
	return b;
}
int minCost(int **input,int r,int c)
{
	int dp[r][c];
	for(int i=r-1;i>=0;i--)
	{
		for(int j=c-1;j>=0;j--)
		{
			
			if(i==r-1&&j==c-1)
			dp[i][j]=input[i][j];
			else if(i==r-1)
			{
				dp[i][j] = dp[i][j+1]+input[i][j];
			}
			else if(j==c-1)
			{
				dp[i][j] = dp[i+1][j]+input[i][j];
			}
			else
			{
				int a = dp[i+1][j];
				int b = dp[i][j+1];
				int d = dp[i+1][j+1];
				int ans = min(a,min(b,d))+input[i][j];
				dp[i][j] = ans;
			}
		}
	}
	return dp[0][0];
	
}
int main()
{
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
    int ans = minCost(input,r,c);
    cout<<ans;
	return 0;
}