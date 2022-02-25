#include<iostream>
using namespace std;
int main()
{
	int *p;
	p=new int[5];
	for(int i=0;i<5;i++)
	{
		p[i]=(i+1);
	}
	int *q;
	q=new int[10];
	for(int i=0;i<5;i++)
	{
		q[i]=p[i];
	}
	delete []p;
	q=p;
	q=NULL;
	return 0;
}
