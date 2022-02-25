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
void swap(int *a,int *b)
{
	int k;
	k= (*a);
	(*a)=(*b);
	(*b)=k;
}
void bubblesort(int *arr,int n,int k)
{
		arr[0] = arr[0]+k;
	for(int i = 1;i<n;i++)
	{
		arr[i]=arr[i]-k;
	}
	cout<<"\nminmum difference ="<<(arr[n-1]-k)-(arr[0]+k);
}
int main()
{
	int n;
	printf("Enter the no. of elements of array\n");
	scanf("%d",&n);
	printf("Enter the difference\n");
	int k;
	cin>>k;
	int *arr;
	arr = (int*)malloc(n*sizeof(int));
	insert(arr,n);
	bubblesort(arr,n,k);
	return 0;
}