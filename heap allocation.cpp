#include<iostream>
using namespace std;
int main()
{
	int a[5];
	int *p;
	p=new int[5];
	a[0]=5;
	p[0]=3
	cout<<a[0]<<"\n"<<p[0];
	
	delete []p;
	return 0;
}
