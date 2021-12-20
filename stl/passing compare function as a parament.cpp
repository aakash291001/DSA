#include<iostream>
#include<algorithm>
using namespace std;
bool comparator(int a,int b)
{
	return a<b;//return true when a is greater than b
}
void bubble_sort(int a[],int n, bool (&comp)(int a,int b))
{
	for(int i=1;i<n-1;i++)
	{
		for(int j=0;j<=(n-i-1);j++)
		{
			if(comp(a[j],a[j+1])){
				swap(a[j],a[j+1]);
			}
		}
	}
}
int main()
{
	int arr[]={100,10,200,3,40};
	int n = sizeof(arr)/sizeof(int);
	bubble_sort(arr,n,comparator);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
} 