#include<iostream>
using namespace std;
int gcd(int a,int b)
{
	if(b=0)
	return a;
	else
	{
		int p;
		p=a%b;
		return(p,b);
	}
}
int main()
{
	int a,b;
	cin>>a;
	cin>>b;
	cout<<gcd(a,b);
	return 0;
}

