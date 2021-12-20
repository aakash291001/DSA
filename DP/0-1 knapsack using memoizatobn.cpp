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
int knapSack2(int wt[],int val[],int W,int n)
{
    if(t[W][n]!=-1)
    {
        return t[W][n];
    }
    else
    {
        if(W==0||n==0)
        {
            t[W][n]=0;
            return t[W][n];
        }
        else
        {
            if(wt[n-1]<=W)
            {
                t[W][n] = max(val[n-1]+knapSack2(wt,val,W-wt[n-1],n-1),knapSack2(wt,val,W,n-1));
                return t[W][n];
            }
            else
            {
                t[W][n] = knapSack2(wt,val,W,n-1);
                return t[W][n];
            }
        }
    }      
}
int knapSack(int wt[],int val[],int W,int n)
{
    memset(t,-1,sizeof(t));
    return knapSack2(wt,val,W,n);
}
int main()
{
    int wt[]={1,2,4,5};
    int val[]={5,4,8,6};
    int W = 5;
    int maxProfit;
    maxProfit = knapSack(wt,val,W,4);
    cout<<"maxProfit = "<<maxProfit; 
    return 0;
}