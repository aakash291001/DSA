#include<iostream>
using namespace std;
void insert(int *arr,int n)
{
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&arr[i]);	
	}
}
void swap(int *a,int *b)
{
	int k;
	k = (*a);
	(*a) = (*b);
	(*b) = k;
}
void display(int *arr,int n)
{
	for(int i = 0;i<n;i++)
	{
		printf("%d\n",arr[i]);	
	}
}
void seperate(int *arr,int n)
{
	for(int i = 0;i<n-1;i++)
	{
		if(arr[i+1]<0)
		{
			for(int j = i+1;j>=1;j--)
			{
				swap(&arr[j],&arr[j-1]);
			}
		}
	}
}
int main()
{
	int n;
	printf("Enter the no. elements of the arry\n");
	scanf("%d",&n);
	int *arr;
	arr = (int*)malloc(n*sizeof(int));
	insert(arr,n);
	seperate(arr,n);
	display(arr,n);
	return 0;
}