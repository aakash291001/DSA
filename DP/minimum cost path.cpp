#include<iostream>
#include<limits.h>
using namespace std;
int min(int a,int b)
{
    if(a<b)
    return a;
    else
    return b;
}
int minCost(int **input,int r,int c,int i,int j)
{
    if(i==r-1&&j==c-1)
    {
        return input[i][j];
    }
    else if(i>=r||j>=c)
    return INT_MAX;
    else
    {
        int a = minCost(input,r,c,i+1,j);
        int b = minCost(input,r,c,i,j+1);
        int d = minCost(input,r,c,i+1,j+1);
        return min(a,min(b,d))+input[i][j];
    }
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
    int ans = minCost(input,r,c,0,0);
    cout<<ans;
    return 0;
}
