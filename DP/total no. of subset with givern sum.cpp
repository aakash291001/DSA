#include<iostream>
using namespace std;
int numSubseq(int a[],int n, int target) {
        int dp[n+1][target+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=target;j++)
            {
                if(i==0)
                    dp[i][j] = 0;
                if(j==0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=target;j++)
            {
                if(a[i-1]>j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j-a[i-1]]+dp[i-1][j];
            }
        }
        return dp[n][target];
    }
int main()
{
    int A[] ={2,3,5,6,8,10};
    cout<<numSubseq(A,6,10);
}