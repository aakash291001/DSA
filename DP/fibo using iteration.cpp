// DP is a bottom up aproach 
// Memoriztion(recursion with array) is top down approach
#include<iostream>
using namespace std;
int fibo(int n)
{
    int A[n+1];
    A[0] = 0;
    A[1] = 1;
    for(int i=2;i<=n;i++)
    {
        A[i] = A[i-1]+A[i-2];
    }
    return A[n];
}
int main()
{
    int n;
    cin>>n;
    int ans = fibo(n);
    cout<<ans;
    return 0;
}