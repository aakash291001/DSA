#include<iostream>
using namespace std;
struct array 
{
	int A[20];
	int size;
	int length;
};
int Union(array *arr1,array *arr2,array *arr3)
{
	int i,j,k;
	i=j=k=0;
	int m,n;
	m=arr1->length;
	n=arr2->length;
	while(i<m&&i<n)
	{
	if(arr1->A[i]<arr2->A[j])
	{
		arr3->A[k]=arr1->A[i];
		i++;
		k++;
	}
	else if(arr1->A[i]>arr2->A[j])
	{
		arr3->A[k]=arr2->A[j];
		j++;
		k++;
	}
	else if(arr1->A[i]==arr2->A[j])
	{
		arr3->A[k]=arr2->A[j];
		j++;
		k++;
		i++;
	}
	}
	
	for(i;i<m;i++)
	{
		arr3->A[k]=arr1->A[i];
    }  
	for(j;j<n;j++)
	{
		arr3->A[k]=arr2->A[j];
    }                                    
	return k;                                  
}
int main()
{
	array arr1{{2,5,6,15,27},20,5};
	array arr2{{3,5,9,10,27},20,5};
	array arr3;
	int k;
	k=Union(&arr1,&arr2,&arr3);
	int i=0;
	while(i<k)
	{
		cout<<arr3.A[i]<<" ";
		i++;
	}
	return 0;
}
