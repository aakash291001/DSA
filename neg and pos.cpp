#include<iostream>
using namespace std;
struct array
{
	int A[20];
	int length;
	int size;
};
void arrange(array *arr)
{
	int i=0;
	int j;
	j=arr->length-1;
	while(i<j)
	{
	while(arr->A[i]<0)
    i++;
    while(arr->A[j]>0)
    j--;
	if(i<j)
	{
		int ex;
		ex=arr->A[i];
		arr->A[i]=arr->A[j];
		arr->A[j]=ex;
	}
    }  
}
int main()
{
	array arr{{-6,3,-8,10,5,-7,-9,12,-4,2},10,20};
	arrange(&arr);
	for(int i=0;i<=arr.length;i++)
	{
		cout<<arr.A[i]<<" ";
	}
	return 0;
}
