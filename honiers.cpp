#include<iostream>
using namespace std;
double expo(int x,int n)
{
	static int p=1;
	if(n==0)
	{
		return 1;
	}
	double r;
	r=1+(x/p)*expo(x,n-1);
	p++;
	return r;
}
int main()
{
	double q;
	q=expo(2,10);
	cout<<q;
	return 0;
}
