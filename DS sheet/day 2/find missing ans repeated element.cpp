#include<bits/stdc++.h>
using namespace std;
//void RM(int A[],int n)
//{
//    vector<int> vec(n+1,0);
//    for(int i=0;i<n;i++)
//    {
//        vec[A[i]]++;
//    }
//    int r,m;
//    for(int i=1;i<=n;i++)
//    {
//        if(vec[i]==2)
//        r = i;
//        else if(vec[i]==0)
//        m =i;
//    }
//    cout<<r<<" "<<m;
//}
//void RM(int A[],int n)
//{
//    int xy=0;
//    for(int i=1;i<=n;i++)
//    {
//        xy = xy^i;
//    }
//    for(int i=0;i<n;i++)
//    {
//        xy = xy^A[i];
//    }
//    int pos1 = xy & ~xy;
//    int x,y;
//    x = y=0;
//    for(int i=0;i<n;i++)
//    {
//        if(A[i]&pos1)
//        {
//            x = x^A[i];
//        }
//        else
//        {
//            y = y^A[i];
//        }
//    }
//    for(int i=1;i<=n;i++)
//    {
//        if(i&xy)
//        {
//            x=x^i;
//        }
//        else
//        y = y^i;
//    }
//    int m = x;
//    int r = y;
//    cout<<r<<" "<<m;
//}
void RM(int A[],int n)
{
    int sum1 = n*(n+1)/2;
    int sum2 = n*(n+1)*(2*n+1)/6;
    int sum1A = 0;
    int sum2A = 0;
    for(int i=0;i<n;i++)
    {
        sum1A+=A[i];
        sum2A+=(A[i]*A[i]);
    }
    int d1 = sum1 - sum1A;
    int d2 = sum2 - sum2A;
    int d3 = d2/d1;
    int m = (d3+d1)/2;
    int r = d3-m;
    cout<<r<<" "<<m;
}
int main()
{
    int A[] = {3,1,2,5,3};
    RM(A,5);
    return 0;
}