#include<iostream>
using namespace std;
bool is_sorted(int *A,int size)
{
	if(size ==0||size ==1)
	return true;
	bool res;
	res =is_sorted(A+1,size-1);
	if(!res)
	{
		return false;
	}
	if
	{
		if(A[0]>A[1])
		{
			return false;
		}
		else
		return true;
	}
}
int main()
{
	cout<<"Enter size of an array\n";
	int n;
	cin>>n;
	cout<<"Enter element of array\n";
	int *A;
	A = new int[n];
	for(int i =0;i<n;i++)
	{
		cin>>A[i];
		
	}
	cout<<"is array sorted\n";
	cout<<is_sorted(A,n+1);
	return 0;
}