#include<iostream>
using namespace std;
void printst(int p,int n,int i)
{
	if(n==0)
	{
		return;
	}
	else
	{
		if(i<=p-n)
		{
			cout<<" * ";
			printst(p,n,i+1);
		}
		else
		{
			cout<<"\n";
			printst(p,n-1,0);
		}
	}
}
int main ()
{
	int n;
	cout<<"Enter no. of rows\n";
	cin>>n;
	printst(n,n,0);
	return 0;
}