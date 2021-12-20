#include<iostream>
using namespace std;
void pallind(int *A,int size,int ele)
{
	if(size==0)
	return;
	pallind(A,size-1,ele);
	if(A[size-1]==ele)
	cout<<size-1<<" ";
}
int main()
{
	cout<<"\nenter size of array\n";
	int n;
	cin>>n;
	int *A;
	A = new int[n];
	for(int i =0;i<n;i++)
	{
		cin>>A[i];
	}
	cout<<"Enter element to be searched\n";
	int ele;
	cin>>ele;
	pallind(A,n,ele);
	return 0;
}