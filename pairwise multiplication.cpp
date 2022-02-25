#include<iostream>
using namespace std;
int main()
{
    long long n;
    long long *A;
    cin>>n;
    A=new long long[n];
    for(long long i=0;i<n;i++)
    {
        cin>>A[i];
    }
    long long x,y;
    x=A[0];
    for(long long i=1;i<n;i++)
    {
        if(A[i]>x)
        {
            x=A[i];
            y=i;
        }
    }
    long long m=0;
    for(long long i=0;i<n;i++)
    {
        if(A[i]>m&&i!=y)
        {
            m=A[i];
        }
    }
    long long p;
    p=m*x;
    cout<<p;
    return 0;
}
