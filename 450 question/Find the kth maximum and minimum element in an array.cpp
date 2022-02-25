#include<iostream>
using namespace std;
void insert(int *arr,int n)
{
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
}
void display(int *arr,int n)
{
	for(int i = 0;i<n;i++)
	{
		printf("%d\n",arr[i]);
	}
}
void swap(int *a,int *b)
{
	int k;
	k = (*a);
	(*a) = (*b);
	(*b) = k;
}
void bubblesort(int *arr,int n)
{
	for(int i = 0;i<n-1;i++)
	{
		int flag=0;
		for(int j=0;j<n-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
				flag++;
			}	
		}
		if(flag==0)
		break;
	}
}
void kmaxmin(int *arr,int n,int k)
{
	int kmin,kmax;
	kmin = arr[k-1];
	kmax = arr[n-k];
	printf("Kth minimum element = %d\n",kmin);
	printf("Kth maximum element = %d\n",kmax);
}
int main()
{
	int n;
	printf("enter the no. of element in array\n");
	scanf("%d",&n);
	int *arr;
	arr = (int*)malloc(n*sizeof(int));
	insert(arr,n);
	int k;
	printf("enter the no. of maximum and minimum element you want");
	scanf("%d",&k);
	printf("elements of the array are\n");
	display(arr,n);
	bubblesort(arr,n);
	printf("elements of the sorted array are\n");
	display(arr,n);
	kmaxmin(arr,n,k);
	return 0;
}