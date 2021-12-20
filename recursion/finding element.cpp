#include<iostream>
using namespace std;
bool findele(int *A,int size,int ele)
{
	if(size == 0)
	{
		return false;
	}
	if(A[0]==ele)
	return true;
	return findele(A+1,size-1,ele);
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
	cout<<findele(A,n,ele);
	return 0;
}