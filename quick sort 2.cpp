#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
  int k;
  k=(*a);
  (*a)=(*b);
  (*b)=k;
}
int partition(int *arr,int l,int h)
{
	int pivot=arr[l];
	int i=l;
	int j =h;
	do
	{
		do{i++;
		}while(arr[i]<=pivot);
		do{j--;
		}while(arr[j]>pivot);
		if(i<j)
		{
			swap(&arr[i],&arr[j]);
		}
	}while(i<j);
	swap(&arr[j],&arr[l]);
	return j;
}
void quicksort(int *a,int l,int h)
{
  int p;
  if(l<h)
  {
    p=partition(a,l,h);
    quicksort(a,l,p);
    quicksort(a,p+1,h);
  }
}
void display(int arr[],int n)
{
	for(int i = 0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
int main()
{
  int A[]={11,20,2,0,9,5,256};
  quicksort(A,0,6);
  display(A,6);
  return 0;
}