#include<iostream>
using namespace std;
int countz(int n)
{
	if(n<10)
	{
		if(n==0)
		return 1;
		else
		 return 0;
	}
	else
	{
		int p = countz(n/10);
		if(n%10==0)
		{
			return 1+p;
		}
		return p;
	}
}
int main()
{
	cout<<"Enter a number\n";
	int n;
	cin>>n;
	int p = countz(n);
	cout<<"No. of zeroes are "<<p;
	return 0;
}