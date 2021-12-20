#include <bits/stdc++.h>
using namespace std;
int t[1002][1002];
int max(int a,int b)
{
    if(a>b)
    return a;
    else
    return b;
}
int knapSack(int wt[],int val[],int W,int n)
{
	for(int i=0;i<n+1;i++)
    {
    for(int j=0;j<W+1;j++)
        {
            if(i==0||j==0)
            {
            	t[i][j]=0;
			}
            else
            {
                if(wt[i-1]<=j)
                {
                    t[i][j] = max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
                }
                else
                {
                	t[i][j] = t[i-1][j];
				}
                
            }
        }
    }
        return t[n][W];
}
int main()
{
    int wt[]={1,3,4,5};
    int val[]={1,4,5,7};
    int W = 7;
    memset(t,-1,sizeof(t));
    int maxProfit = knapSack(wt,val,W,4);
    cout<<"maxProfit : "<<maxProfit;
    return 0;
}