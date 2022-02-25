#include<iostream>
using namespace std;
void insert(int *arr,int N)
{
	for(int i =0;i<N;i++)
	{
		scanf("%d",&arr[i]);
	}
}
void display(int *arr,int N)
{
	for(int i =0;i<N;i++)
	{
		printf("%d\n",arr[i]);
	}
}
void maxmin(int *arr,int N)
{
	int max,min;
	max = min = arr[0];
	for(int i =0; i<N;i++)
	{
		if(arr[i]>max)
		max=arr[i];
		else if(arr[i]<min)
		min=arr[i];
	}
	printf("\nMaximum number is :%d\n",max);
	printf("\nMinimum number is :%d\n",min);
}
int main()
{
	int N;
	printf("Enter the number of elements of array\n");
	scanf("%d\n",&N);
	int *arr;
	arr = (int*)malloc(N*sizeof(int));
	insert(arr,N);
	display(arr,N);
	maxmin(arr,N);
	return 0;
}