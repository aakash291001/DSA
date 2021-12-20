#include<iostream>
#include<cmath>
#include<limits.h>
using namespace std;

int mincount2(int p,int dp[])
{
	if(dp[p]!=-1)
	return dp[p];
    if(p<=3)
    return p;
    else
    {
        int n = sqrt(p);
        int min = INT_MAX;
        for(int i=1;i<=n;i++)
        {
            int s = mincount2(p-i*i,dp)+1;
            if(s<min)
            min = s;
        }
        dp[p] = min;
        return min;
    }
}
int mincount(int p)
{
	int dp[p+1];
	for(int i=0;i<=p;i++)
	{
		dp[i]=-1;
	}
	return mincount2(p,dp);
}
int main()
{
    int n;
    cin>>n;
    cout<<mincount(n);
    return 0;
}