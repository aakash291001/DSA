#include<iostream>
using namespace std;
void merge(int A[], int l, int mid, int h)
    {
        int i=l,j=mid+1,k=l;
  int C[l+h];
  while(i<=mid&&j<=h)
  {
    if(A[i]<A[j])
    {
      C[k]=A[i];
      i++;
      k++;
    }
    else if(A[i]>=A[j])
    {
      C[k]=A[j];
      j++;
      k++;
    }
  }  
  for(;j<=h;j++)
    {
      C[k]=A[j];
      k++;
    }
    for(;i<=mid;i++)
    {
      C[k]=A[i];
      k++;
    }
    for(int q=l;q<=(h);q++)
    {
      A[q]=C[q];
    }
    }
    void mergeSort(int A[], int l, int h)
    {
        int mid;
  if(l<h)
  {
    mid=(l+h)/2;
    mergeSort(A,l,mid);
    mergeSort(A,mid+1,h);
    merge(A,l,mid,h);
  }
}
int main()
{
	cout<<"Enter size of array\n";
	int n;
	cin>>n;
	cout<<"\nEnter the elements of array\n";
	int A[n];
	for(int i =0;i<n;i++)
	{
		cin>>A[i];
	}
	mergeSort(A,0,n-1);
	for(int i = 0;i<n;i++)
	{
		cout<<A[i]<<" ";
	}
	return 0;
}