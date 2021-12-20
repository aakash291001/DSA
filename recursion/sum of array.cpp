#include<iostream>
using namespace std;
int sum_arr(int *A,int size)
{
	if(size == 0)
	{
		return 0;
	}
	int small = sum_arr(A+1,size-1);
	return A[0]+small;
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
	int sum = sum_arr(A,n);
	cout<<"\n sum = "<<sum;
	return 0;
}
