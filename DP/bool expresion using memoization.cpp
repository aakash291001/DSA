#include<bits/stdc++.h>
using namespace std;
long long int dp[501][501][2];
long long int solve(string &str,long long int i,long long int j,long long int value)
{
    if(i>j)
    return 0;
    if(dp[i][j][value]!=-1)
	{
		return dp[i][j][value];
	}
	if(i==j)
	{
		if(value==1)
		return str[i]=='T';
		else
		return str[i]=='F';
	}
	long long int co=0;
	for(int k=i+1;k<=j-1;k=k+2)
	{
		long long int lt,lf,rt,rf;
		if(dp[i][k-1][1]!=-1)
		lt = dp[i][k-1][1];
		else
		lt = dp[i][k-1][1]=solve(str,i,k-1,1);
		if(dp[i][k-1][0]!=-1)
		lf = dp[i][k-1][0];
		else
		lf= dp[i][k-1][0]=solve(str,i,k-1,0);
		if(dp[k+1][j][1]!=-1)
		rt = dp[k+1][j][1];
		else
		rt = dp[k+1][j][1]=solve(str,k+1,j,1);
		if(dp[k+1][j][0]!=-1)
		rf = dp[k+1][j][0];
		else
		rf = dp[k+1][j][0]=solve(str,k+1,j,0);
		if(str[k]=='^')
        {
            if(value==1)
            co+= lt*rf+lf*rt;
            else
            co+= lt*rt+rf*lf;
        }
        else if(str[k]=='&')
        {
            if(value == 1)
            {
                co+= lt*rt;
            }
            else
            co+= lf*rt+lf*rf+lt*rf;
        }
        else if(str[k]=='|')
        {
            if(value == 1)
            co+= (lf*rt+lt*rt+lt*rf);
            else
            co+= (lf*rf);
        }
	}
	dp[i][j][value] = co%1003;
	return dp[i][j][value];	
}
int main()
{
	memset(dp,-1,sizeof(dp));
	string str = "T|T&F^T";
    cout<<solve(str,0,str.length()-1,1);
	return 0;
}