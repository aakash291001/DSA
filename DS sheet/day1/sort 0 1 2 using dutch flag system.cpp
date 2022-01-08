#include<bits/stdc++.h>
using namespace std;
void swap(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void sort012(int A[],int n)
{
    int l,m,h;
    l = m = 0;
    h = n-1;
    while(m<=h)
    {
        if(A[m]==0)
        {
            swap(A[m],A[l]);
            m++;
            l++;
        }
        else if(A[m]==1)
        {
            m++;
        }
        else if(A[m]==2)
        {
            swap(A[h],A[m]);
            h--;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<A[i];
    }
}
int main()
{
    int A[]= {0,1,2,0,1,2};
    sort012(A,6);
    return 0;
}