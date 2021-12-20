#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int min(int a,int b)
{
    if(a<b)
    return a;
    else
    return b;
}
int adr(string s1,string s2)
{
    int l1,l2;
    l1 = s1.length();
    l2 = s2.length();
    int dp[l1][l2];
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<l1;i++)
    {
        for(int j=0;j<l2;j++)
        {
            if(i==0&&j==0)
            {
                dp[i][j] =0; 
            }
            else if(i==0)
            {
                dp[i][j]=j;
            }
            else if(j==0)
            {
                dp[i][j]=i;
            }
            else
            {
				if(s1[i]==s2[j])
				{
					dp[i][j] = dp[i-1][j-1];
				}
            	else
            	{
            	    int a,d,r;
           	     	a = dp[i-1][j];
           	    	d = dp[i][j-1];
            	    r = dp[i-1][j-1];
            	    dp[i][j] = min(a,min(d,r))+1;
            	}	
			}
        }
    }
    return dp[l1-1][l2-1];
}
int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    int ans = adr(s1,s2);
    cout<<ans;
    return 0;
}