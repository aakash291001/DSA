#include<iostream>
using namespace std;
int fib(int n)
{
	int temp;
	int A[1000];
	A[0]=0;
	A[1]=1;
	for(int i=2;i<n;i++)
	{
		int temp;
		temp = A[n-2]+A[n-1];
	}
	return temp;
}
int main()
{
	int n;
	cin>>n;
	int x;
	x= fib(n);
	cout<<x;
	return 0;
}