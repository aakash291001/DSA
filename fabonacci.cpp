#include<iostream>
using namespace std;
void fab(int n)
{
	int i =0;
	int A[n+1];
	A[0]=0;
	A[1]=1;
	for(i=2;i<=n;i++)
	{
		A[i]=A[i-1]+A[i-2];
	}
	cout<<A[n];
}
int main()
{
	cout<<"Enter the number";
	int n;
	cin>>n;
	fab(n);
	return 0;
}
