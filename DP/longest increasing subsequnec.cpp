#include<iostream>
using namespace std;
int lis(int a[],int size)
{
    int dp[size];
    dp[0] = 1;
    for(int i=1;i<size;i++)
    {
        int max = 0;
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[i])
            {
                if(max<dp[j])
                max = dp[j];
            }
        }
        dp[i] = max + 1;
    }
    int max = 0;
    for(int j=0;j<size;j++)
    {
        if(max<dp[j])
        max = dp[j];
    }
    return max;
}
int main()
{
    int A[] = {5,4,11,1,16,8};
    cout<<lis(A,6);
    return 0;
}