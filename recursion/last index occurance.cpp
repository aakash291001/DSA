#include<iostream>
using namespace std;
int findpos(int *A,int size,int ele)
{
	if(size==0)
	{
		return -1;
	}
	if(ele==A[size-1])
	return size-1;
	else
	{
		int pos = findpos(A,size-1,ele);
		if(pos==-1)
		return pos;
		else
		return pos;
	}
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
	cout<<"Last position is "<<findpos(A,n,ele);
	return 0;
}