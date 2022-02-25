#include<iostream>
using  namespace std;
struct array
{
	int *A;
	int size;
	int length;
};
void display(struct array arr)
{
	cout<<"Elements Of the array are"<<"\n";
	for(int i=0;i<arr.length;i++)
	{
		cout<<arr.A[i]<<"\n";
	}
}
int main()
{
	array arr;
	cout<<"Enter size of an array\n";
	cin>>arr.size;
	arr.A=new int[arr.size];
	arr.length=0;
	cout<<"Enter the numberof elements you wantto enter\n";
	cin>>arr.length;
	cout<<"Enter all elements"<<"\n";
	for(int i=0;i<arr.length;i++)
	{
		cin>>arr.A[i];
		
	}
	display(arr);
	delete arr.A;
	return 0;
}
