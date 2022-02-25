#include<iostream>
using namespace std;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// A function to implement bubble sort
void bubblesort(int *arr, int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)     
 
       // Last i elements are already in place  
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}
void insert(int *arr,int n)
{
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
}
void display(int *arr,int n)
{
	for(int i = 0;i<n;i++)
	{
		cout<<arr[i]<<"\n";
	}
}
void merge(int *arr1,int *arr2,int n,int m)
{
	for(int i =0,j=0;i<n&&j<m;)
	{
		if(arr1[i]<arr2[j])
		{
			i++;
		}
		else
		{
			swap(&arr1[n-1],&arr2[j]);
			bubblesort(arr1,n);
			i++;
			j++;
		}
	}
	bubblesort(arr2,m);
	display(arr1,n);
	display(arr2,m);
}
int main()
{
	cout<<"Enter the size of array1\n";
	int n;
	cin>>n;
	cout<<"Enter the elements pf first array\n";
	int *arr1;
	arr1 = (int*)malloc(n*sizeof(int));
	insert(arr1,n);
	cout<<"Enter the size of array 2\n";
	int m;
	cin>>m;
	cout<<"Enter the elements of second array\n";
	int *arr2;
	arr2 = (int*)malloc(m*sizeof(int));
	insert(arr2,m);
	merge(arr1,arr2,n,m);
	return 0;
}