#include<iostream>
using namespace std;
void leftRotate(int arr[], int n, int d) {
        // code here
        int a[n];
        int k;
        for(int i =0;i<n;i++)
        {
            a[i]=arr[i];
        }
	    for(int i = 0;i<n;i++)
	    {
	        if(i<d)
	        {
	            arr[d+(n-1-d-d+1)+i]=a[i];
	        }
	        else if(i>=d)
	        {
	        	
	            arr[i-d]=a[i];
	        }
	    }
    }
void display(int *arr,int n)
{
	for(int i = 0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
int main()
{
	int n;
	cout<<"Enter the size of array\n";
	cin>>n;
	int *arr;
	arr = (int*)malloc(n*sizeof(int));
	for(int i = 0;i<n;i++)
	{
		cin>>arr[i];
	}
	int d;
	cout<<"Enter the no. of rotation\n";
	cin>>d;
	leftRotate(arr,n,d);
	display(arr,n);
	return 0;
}