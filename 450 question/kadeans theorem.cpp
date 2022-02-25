#include<iostream>
using namespace std;
void insert(int *arr,int n)
{
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
}
void display(int *arr,int n)
{
	int i =0;
	while(i<n)
	{
		cout<<arr[i]<<"\n";
		i++;
	}
}
void kaeden(int *arr,int n)
{
	int sumtn=0;
	int maxsum=0;
	for(int i = 0;i<n;i++)
	{
		sumtn=sumtn+arr[i];
		if(sumtn<0)
		{
			sumtn=0;
		}
		else
		{
			if(sumtn>maxsum)
			maxsum=sumtn;
		}
	}
	cout<<"\nMaxsum is "<<maxsum;
}
int main()
{
	cout<<"Enter the size of array\n";
	int n;
	cin>>n;
	cout<<"Enter the elements of array\n";
	int *arr;
	arr=(int*)malloc(n*sizeof(int));
	insert(arr,n);
	display(arr,n);
	kaeden(arr,n);
	return 0;
}