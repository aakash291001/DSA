#include<iostream>
using namespace std;
void insert(int *arr,int n)
{
	for(int i = 0;i<n;i++)
	{
		cin>>arr[i];
	}
}
void display(int *arr,int n)
{
	for(int i = 0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
void sumpair(int *arr,int n,int key)
{
	for(int i = 0;i<n;i++)
	{
		int k;
		int flag=0;
		k=arr[i];
		for(int j = 0;j<n;j++)
		{
			if(i!=j)
			{
				if((k+arr[j])==key)
				{
				
				cout<<arr[j]<<"&"<<k<<"\nIndices are ="<<j<<"&"<<i;
				flag++;
				break;
				}
			}
		}
		if(flag!=0)
		break;
	}
}
int main()
{
	int n;
  	cout<<"Enter the size of array\n";
  	cin>>n;
  	int *arr;
  	arr=(int*)malloc(n*sizeof(int));
  	insert(arr,n);
  	display(arr,n);
  	cout<<"Enter the no. to be searched\n";
  	int key;
  	cin>>key;
  	sumpair(arr,n,key);
	return 0;
}