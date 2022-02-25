#include<iostream>
using namespace std;
struct array
{
	int A[100];
	int length;
	int size;
};
static int pos;
void search(array arr,int ele)
{
	int m=0;
	for(int i=0;i<arr.length;i++)
	{
		if(arr.A[i]==ele)
		{
			cout<<"Element found"<<"\n";
			pos=i;
			m++;
		}
	}
	if(m==0)
	{
		cout<<"element not found";
		exit(0);
	}
}
void dele(array *arr)
{
	for(int i=pos;i<arr->length;i++)
	{
		arr->A[i]=arr->A[i+1];
	}
	arr->A[arr->length-1]=NULL;
	arr->length--;
}
void display(array arr)
{
	for(int i=0;i<arr.length;i++)
	{
		cout<<arr.A[i]<<"\n";
	}
}
int main()
{
	int ele;
	array arr{{20,10,90,80,50},5,10};
	cout<<"Enter the element to be deleted"<<"\n";
	cin>>ele;
	search(arr,ele);
	dele(&arr);
	display(arr);
	return 0;
}
