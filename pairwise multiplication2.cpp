#include<iostream>
using namespace std;
int main()
{
    int n;
    long long *A;
    cin>>n;
    A=new long long[n];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    int x,y;
    x=A[0];
    for(int i=1;i<n;i++)
    {
        if(A[i]>x)
        {
            x=A[i];
            y=i;
        }
    }
    long long m=0;
    for(int i=0;i<n;i++)
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
