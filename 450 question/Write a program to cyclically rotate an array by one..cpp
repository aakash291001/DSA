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
void swap(int *p,int *q)
{
	int k;
	k = (*p);
	(*p) = (*q);
	(*q) = k;
}
void rotate(int *arr,int n)
{
	int a;
	a=arr[0];
	for(int i = 1;i<n;i++)
	{
		swap(&arr[i],&a);
	}
	arr[0]=a;
}
int main()
{
	int n;
	printf("enter the no. elements of the array\n");
	scanf("%d",&n);
	int *arr;
	arr = (int*)malloc(n*sizeof(int));
	printf("enter the elements of array\n");
	insert(arr,n);
	printf("Elements of the array are\n");
	display(arr,n);
	rotate(arr,n);
	printf("Rotated Element by 1 clockwise\n");
	display(arr,n);
	return 0;
}