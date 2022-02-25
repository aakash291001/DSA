#include<iostream>
using namespace std;
double ts(int x,int n)
{
	double r;
	static double p=1;
	static double f=1;
	if(n==0)
		return 1;
	r=ts(x,n-1);
	p=p*x;
	f=f*n;
	return r+p/f;
	
}
int main()
{
	int b,c;
	cin>>b;
	cin>>c;
	cout<<"\n"<<ts(b,c);
	return 0;
}
