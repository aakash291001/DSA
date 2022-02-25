#include<bits/stdc++.h>
using namespace std;
void merge(vector<int> &A,int l,int m,int h,int &count)
{
    vector<int> B(h+1);
    int k=l;
    int i,j;
    i = l;
    j = m+1;
    while(i<=m&&j<=h)
    {
        if(A[i]<A[j])
        {
            B[k] = A[i];
            k++;
            i++;
        }
        else
        {
            B[k] = A[j];
            int temp = m+1-i;
            j++;
            k++;
            count+=temp;
        }
    }
    while(i<=m)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while(j<=h)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for(int p=l;p<=h;p++)
    {
        A[p] = B[p];
    }
}
void mergeSort(vector<int> &A,int l,int h,int &count)
{
    if(l<h)
    {
        int m = (l+h)/2;
        mergeSort(A,l,m,count);
        mergeSort(A,m+1,h,count);
        merge(A,l,m,h,count);
    }
}
int main()
{
    vector<int> vec{5,4,3,2,1};
    int l =0;
    int h = vec.size()-1;
    int count =0;
    mergeSort(vec,l,h,count);
    cout<<count;
    return 0;
}