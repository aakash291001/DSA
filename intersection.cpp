#include<iostream>
using namespace std;
struct array 
{
	int A[20];
	int size;
	int length;
};
int intersection(array *arr1,array *arr2,array *arr3)
{
	int i,j,k;
	i=j=k=0;
	int m,n;
	m=arr1->length;
	n=arr2->length;
	while(i<m&&j<n)
	{
		if(arr1->A[i]<arr2->A[j])
		{
			i++;
		}
		else if(arr1->A[i]>arr2->A[j])
		{
			j++;
		}
		else if(arr1->A[i]==arr2->A[j])
		{
			arr3->A[k]=arr1->A[i];
			i++;
			j++;
			k++;
		}
		
	}
	return k;
}
int main()
{
	array arr1{{2,5,6,15,27},20,5};
	array arr2{{3,5,9,10,27},20,5};
	array arr3;
	int k;
	k=intersection(&arr1,&arr2,&arr3);
	int i=0;
	while(i<k)
	{
		cout<<arr3.A[i]<<" ";
		i++;
	}
	return 0;
}
