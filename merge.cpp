#include<iostream>
using namespace std;
struct array
{
	int A[10];
	int size;
	int length;
};
void merge(array *arr1,array *arr2,array *arr3)
{
	int i,j,k;
	i=0;j=0;k=0;
	int m,n;
	m=arr1->length;
	n=arr2->length;
	while(i<m&&j<n)
	{
		if(arr1->A[i]<arr2->A[j])
		{
			arr3->A[k]=arr1->A[i];
			i++;
			k++;
		}
		else
		{
			arr3->A[k]=arr2->A[j];
			j++;
			k++;
		}
	}
	for(;i<m;i++)
	{
		arr3->A[k]=arr1->A[i];
	}
	for(;j<n;j++)
	{
		arr3->A[k]=arr2->A[j];
	}
}
int main()
{
	array arr1{{1,5,7,8,10},10,5};
	array arr2{{2,4,6,9,11},10,5};
	array arr3;
	merge(&arr1,&arr2,&arr3);
	for(int i=0;i<10;i++)
	{
		cout<<arr3.A[i]<<" ";
	}
	return 0;
}
