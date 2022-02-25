#include<iostream>
using namespace std;
void insert(int *arr,int n)
{
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
}
void display(int *arr,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d\n",arr[i]);
	}
}
int add(int *arr,int i,int q)
{
	int sum = 0;
	for(i;i<=q;i++)
	{
		sum = sum+arr[i];
	}
	return sum;
}
void maxsumC(int *arr,int n)
{
	int l,r;
	int maxsum=0;
	for(int p = 0;p<n;p++)
	{
		for(int q=n-1;q>=p;q--)
		{
			int sum;
			sum=0;
			for(int i = p;i<=q;i++)
			{
				sum = add(arr,i,q);
				if(maxsum<sum)
				{
					maxsum=sum;
					l = i;
					r = q;
					
				}
			}
			
		}
	}
	printf("\nmaxsum is = %d",maxsum);
	printf("\nThe sub array is\n");
		for(int i = l;i<=r;i++)
		{
			printf("%d\n",arr[i]);	
		}
}
int main()
{
	int n;
	printf("enter the no. of elements\n");
	scanf("%d",&n);
	printf("Enter the elements of array\n");
	int *arr;
	arr = (int*)malloc(n*sizeof(int));
	insert(arr,n);
	maxsumC(arr,n);
	return 0;
}