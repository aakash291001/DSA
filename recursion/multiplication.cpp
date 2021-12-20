#include<iostream>
using namespace std;
int mult(int m,int n)
{
	if(n==0)
	{
		return 0;
	}
	if(n==1)
	{
		return m;
	}
	else 
	return m+mult(m,n-1);
}
int main()
{
	cout<<"Enter two numbers\n";
	int m,n;
	cin>>m>>n;
	int p = mult(m,n);
	cout<<"Multiplication = "<<p;
	return 0;
}