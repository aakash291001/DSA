#include<iostream>
using namespace std;
void display(int* arr,int N)
{
	for(int i = 0;i<N;i++)
	{
		cout<<"\n"<<arr[i];
	}
}
void rev(int* arr,int N)
{
	if(N%2==0)
	{
		int p;
		for(int i = 0;i<=(N-2)/2;i++)
		{
			p=arr[i];
			arr[i]=arr[(N-1)-i];
			arr[(N-1)-i]=p;
		}
	}
	else if(N%2==1)
	{
		int p;
		for(int i =0;i<=(N-3)/2;i++)
		{
			p=arr[i];
			arr[i]=arr[N-(i+1)];
			arr[N-(i+1)] = p;
		}
	}
	else if(N==0)
	{
		printf("Array is empty");
	}
}
int main()
{
	int N;
	printf("\nEnter the no. of elements in array\n");
	cin>>N;
	int *arr;
	arr=(int*)malloc(N*sizeof(int));
	int i = 0;
	while(i<N)
	{
		cin>>arr[i];
		i++;
	}
	display(arr,N);
	rev(arr,N);
	display(arr,N);
	return 0;
}