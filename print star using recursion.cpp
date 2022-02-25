#include<iostream>
using namespace std;
void prints(int n,int i)
{
	if(n==0)
	{
		return ;
	}
	else
	{
		if(i<n)
		{
			cout<<"* ";
			prints(n,i+1);
				}
				else
				{
					cout<<"\n";
					prints(n-1,0);
				}
		
	}
}
int main ()
{
	int n;
	cout<<"Enter no. of rows\n";
	cin>>n;
	prints(n,0);
	return 0;
}