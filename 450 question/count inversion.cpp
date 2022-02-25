#include<iostream>
using namespace std;
void display(int arr[],int n)
{
	for(int i =0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
int cnt_inv(int arr[],int n)
{
	int count=0;
	for(int i =0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j])
			count++;
		}
	}
	return count;
}
int main()
{
	int arr[]={3,1,2,0};
	display(arr,4);
	cout<<"answer is "<<cnt_inv(arr,4);
	return 0;
}