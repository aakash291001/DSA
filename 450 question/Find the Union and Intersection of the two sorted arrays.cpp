#include<iostream>
using namespace std;
void insert(int *arr,int n)
{
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
}
void display(int *arr,int n)
{
	int i = 0;
	for(i=0;i<n;i++)
	{
	  printf("%d\n",arr[i]);
	}
}
void UNION(int *arr1,int *arr2,int *arr3,int n1,int n2)
{
	
	int i =0;
	int j =0;
	int k =0;
	while(arr1[i]!='\0'&&arr2[j]!='\0')
	{
		if(arr1[i]<arr2[j])
		{
			arr3[k]=arr1[i];
			i++;
			k++;
		}
		else if(arr1[i]>arr2[j])
		{
			arr3[k]=arr2[j];
			j++;
			k++;
		}
		else if(arr1[i]==arr2[j])
		{
			arr3[k]=arr2[j];
			j++;
			i++;
			k++;
		}
	}
	if(arr1[i]!='\0')
	{
		while(arr1[i]!='\0')
		{
			arr3[k]=arr1[i];
			i++;
			k++;
		}
	}
	else if(arr2[j]!='\0')
	{
		while(arr2[j]!='\0')
		{
			arr3[k]=arr2[j];
			j++;
			k++;
		}
	}
}
void intersection(int *arr1,int *arr2,int *arr3,int n1,int n2)
{
	
	int i =0;
	int j =0;
	int k =0;
	while(arr1[i]!='\0'&&arr2[j]!='\0')
	{
		if(arr1[i]<arr2[j])
		{
			i++;
		}
		else if(arr1[i]>arr2[j])
		{
			j++;
		}
		else if(arr1[i]==arr2[j])
		{
			arr3[k]=arr2[j];
			j++;
			i++;
			k++;
		}
	}
}
int main()
{
	int *arr1,*arr2;
	int n1,n2;
	printf("Enter the no. of element of array A\n");
	scanf("%d",&n1);
	printf("Enter the no. of element of array B\n");
	scanf("%d",&n2);
	arr1 = (int*)malloc(n1*sizeof(int));
	arr2 = (int*)malloc(n1*sizeof(int));
	printf("Enter the elements of array A\n");
	insert(arr1,n1);
	printf("Enter the elements of array B\n");
	insert(arr2,n2);
	display(arr1,n1);
	display(arr2,n2);
	int *arr3;
	arr3 = (int*)malloc((n1+n2)*sizeof(int));
	printf("Elemtnts of array A are\n");
	display(arr1,n1);
	printf("Elements of array B are\n");
	display(arr2,n2);
	UNION(arr1,arr2,arr3,n1,n2);
	int n;
	if(n1>n2)
	n=n1;
	else
	n=n2;
	int *arr4;
	arr4 = (int*)malloc(n*sizeof(int));
	printf("Elements of Union of array\n");
	display(arr3,n2+n1);
	intersection(arr1,arr2,arr4,n1,n2);
	printf("Elements of the intersection of array\n");
	display(arr4,n);
	return 0;
}