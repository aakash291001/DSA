#include<iostream>
using namespce std;
struct array arr
{
	int *A;
	int size;
	int length;
};
void Isort(array *arr,int ele)
{
	int pos;
	for(int i=0;i<arr->length;i++)
	{
		if(arr->A[i]>ele)
		{
			pos=i;
		break;
		}
	}
	int l=arr->length;
	for( ;l>=pos;l--)
	{
		arr->A[l]=arr->A[l-1];
	}
	arr->A[pos]=ele;
}
void Delete(array *arr,int ele,int pos)
{
	for(int i=pos;arr->length-1;i++)
	{
		
	}
}
int main()
{
	struct array arr1;
	int ch;
	printf("Enter The SIze of Array");
	scanf("%d",&arr1.size);
	arr1.A=(int*)malloc(arr1.size*sizeof(int));
	printf("Menu\n");
	printf("1 Insert\n");
	printf("2 Delete\n");
	printf("3 Search\n");
	printf("4 Sum\n");
	printf("5 Display\n");
	printf("6 Exit\n");	
	switch(ch)
	{
		case 1: printf("Enter an element\n");
		scanf("%d",&ele);
		insert(&arr1,ele);
		break;
		
		case 2: 
		printf("Enter the Element to be deleted");
		scanf("%d",ele);
		
		}	
	return 0;  
}
