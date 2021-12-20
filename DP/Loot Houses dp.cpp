#include<iostream>
#include<limits.h>
using namespace std;

	int max(int a,int b)
	{
	    if(a>b)
	    return a;
	    else
	    return b;
	}
    int theif2(int a[],int size)
    {
    	int dp[size+1];
    	memset(dp,-1,sizeof(dp));
    	dp[0] = 0;
    	dp[1] = a[0];
    	dp[2] = max(a[1],a[0]);
    	for(int i=2;i<size;i++)
    	{
    		dp[i+1] = max(dp[i],dp[i-1]+a[i]);
		}
		return dp[size];
	}
    int main()
{
    int A[] = {97,22,349,200,169,485,282,235,54,500,419,439,401,289,128,468,229,394,149,484,308};
    cout<<theif2(A,21);
    return 0;
}