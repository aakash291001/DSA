#include<iostream>
using namespace std;
struct array
{
	int A[100];
	int length;
	int size;
};
void add(array *arr,int num)
{
	arr->A[arr->length]=num;
	arr->length++;
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
	array arr{{1,2,3,4,5},5,10};
	cout<<"Unmodified array"<<"\n";
	display(arr);
	add(&arr,4);
	cout<<"After Modification"<<"\n";
	display(arr);
	return 0;
}
