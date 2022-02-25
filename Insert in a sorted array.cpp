#include<iostream>
using namespace std;
struct array
{
	int A[20];
	int length;
	int size;
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
int main()
{
	array arr{{1,2,3,4,5,6,7,9,10,11},10,20};
	cout<<"Enter the element to be entered"<<"\n";
	int ele;
	cin>>ele;
	Isort(&arr,ele);
	for(int i=0;i<=arr.length;i++)
	{
		cout<<arr.A[i]<<"\n";
	}
	return 0;
}
