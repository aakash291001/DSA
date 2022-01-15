#include<bits/stdc++.h>
using namespace std;
void merge(long long *A,long long l,long long m,long long h,long long &count)
{
    long long n1,n2;
    n1 = m+1-l;
    n2 = h-m;
    long long left[n1],right[n2];
    for(long long i=0;i<m+1-l;i++)
    {
        left[i] = A[l+i];
    }
    for(long long i=0;i<h-m;i++)
    {
        right[i] = A[m+1+i];
    }
    long long i = 0;
    long long j = 0;
    long long k = l;
    while(i<=n1-1&&j<=n2-1)
    {
        if(left[i]<=right[j])
        {
            A[k] = left[i];
            k++;
            i++;
        }
        else
        {
            A[k] = right[j];
            long long temp = n1-i;
            j++;
            k++;
            count+=temp;
        }
    }
    while(i<=n1-1)
    {
        A[k] = left[i];
        k++;
        i++;
    }
    while(j<=n2-1)
    {
        A[k] = right[j];
        k++;
        j++;
    }
}
void mergeSort(long long *A,long long l,long long h,long long &count)
{
    if(l<h)
    {
        long long m = (l+h)/2;
        mergeSort(A,l,m,count);
        mergeSort(A,m+1,h,count);
        merge(A,l,m,h,count);
    }
}
int main()
{
	long long A[] = {5,4,3,2,1};
    long long l =0;
    long long h = sizeof(A)/sizeof(long long)-1;
    long long count =0;
    mergeSort(A,l,h,count);
    cout<<count;
    return 0;
}