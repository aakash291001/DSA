#include<iostream>
using namespace std;
void insert(int *arr,int n)
{
	for(int i = 0;i<n;i++)
	{
		cin>>arr[i];
	}
}
void swap(int *a,int *b)
{
	int k;
	k=(*a);
	(*a)=(*b);
	(*b)=k;
}
void display(int arr[],int n)
{
	for(int i = 0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
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
void quicksort(int *arr,int l,int h)
{
	int p;
	if(l<h)
	{
		p=partition(arr,l,h);
		quicksort(arr,l,p);
		quicksort(arr,p+1,h);
	}
}
int main()
{
	int arr[]={11,20,2,0,9,5,256};
	int n;
	n=6;
	quicksort(arr,0,6);
	display(arr,n);
	return 0;
}