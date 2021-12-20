#include<iostream>
#include<algorithm>
using namespace std;
bool comparator(int a,int b)
{
	return a>b;//return true when a is greater than b
}
int main()
{
	int arr[]={100,10,200,3,40};
	int n = sizeof(arr)/sizeof(int);
	sort(arr,arr+n,comparator);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}