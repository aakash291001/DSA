#include<iostream>
using namespace std;
struct array
{
	int A[100];
	int length;
	int size;
};
void append(array *arr,int num,int pos)
{
	for(int i=arr->length-1;i>=pos;i--)
	{
		arr->A[i+1]=arr->A[i];
	}
	arr->A[pos]=num;
	arr->length=arr->length+1;
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
	int pos;
	array arr{{20,30,40,60,70},5,10};
	int num;
	cout<<"Enter the number you want to append"<<"\n";
	cin>>num;
	cout<<"Enter where you want to enter this number";
	cin>>pos;
	append(&arr,num,pos);
	display(arr);
	return 0;
}
