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
	for(int i = 0;i<n;i++)
	{
		cout<<arr[i]<<"\n";
	}
}
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
 
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void merge(int *arr1,int *arr2,int n,int m)
{
	int i,j,k;
	for(i =0,j=0,k=n-1;i<=k&&j<m&&i<n;)
	{
			if(arr1[i]<arr2[j])
			{
				i++;
			}
			else
			{
				swap(&arr1[k],&arr2[j]);
				k--;
				j++;
			}
	}
	quickSort(arr1, 0, n - 1);
	quickSort(arr2, 0 , m - 1);
}
int main()
{
	cout<<"enter size of array 1\n";
	int n,m;
	cin>>n;
	cout<<"Enter size of array 2\n";
	cin>>m;
	cout<<"Enter elements of first array\n";
	int *arr1,*arr2;
	arr1=(int*)malloc(n*sizeof(int));
	arr2=(int*)malloc(m*sizeof(int));
	insert(arr1,n);
	cout<<"Enter elements of second array\n";
	insert(arr2,m);
	merge(arr1,arr2,n,m);
	display(arr1,n);
	display(arr2,m);
	return 0;
}