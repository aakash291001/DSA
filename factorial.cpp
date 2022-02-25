#include<iostream>
using namespace std;
int fact(int n)
{
	int p;
	if(n>0)
	{
	p=n*fact(n-1);
	return p;
	}
	else
	return 1; 
}
int main()
{
	int n;
	cin>>n;
	cout<<"\n"<<fact(n);
	return 0;
}
