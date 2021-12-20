#include<iostream>
#include<limits.h>
using namespace std;
int dp[1000000];
	int max(int a,int b)
	{
	    if(a>b)
	    return a;
	    else
	    return b;
	}
	int theif(int *a,int size)
    {
        if(dp[size]!=-1)
        {
            return dp[size];
        }
        else
        {
            if(size<=0)
            return dp[0];
            else if(size==1)
            {
                dp[size] = a[0];
	            return dp[size];
            }
	        else if(size==2)
	        {
	           dp[size] = max(a[0],a[1]);
	           return dp[size];   
	        }
            else
            {   
                dp[size] = max(theif(a,size-2)+a[size-1],theif(a,size-1));
                return dp[size];
            }
        }
    }
    int main()
{
	memset(dp,-1,sizeof(dp));
	    dp[0] = 0;
    int A[] = {97,22,349,200,169,485,282,235,54,500,419,439,401,289,128,468,229,394,149,484,308};
    cout<<theif(A,21);
    return 0;
}