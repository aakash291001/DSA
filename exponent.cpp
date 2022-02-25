#include<iostream>
using namespace std;
int expo(int m,int n)
{
	int p;
	if(n==0)
	return 1;
	else 
	{
		p=expo(m,n-1)*m;
		return p;
	}
}
int main()
{
	int p,q;
	cin>>p;
	cout<<"\n";
	cin>>q;
	cout<<expo(p,q);
	return 0;
}
