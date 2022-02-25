#include<iostream>
using namespace std;
void insert(int *arr,int N)
{
	for(int i = 0;i<N;i++)
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
void heap(int *arr,int n)
{
	
}
int main()
{
	int N;
	printf("Enter the no. of element in array\n");
	scanf("%d\n",&N);
	int *arr;
	arr = (int*)malloc(N*sizeof(int));
	insert(arr,N);
	display(arr,N);
	return 0;
}