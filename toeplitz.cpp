#include<iostream>
using namespace std;
struct Toeplitz
{
	int A[9];
	int n;
};
void set(Toeplitz *t,int i,int j,int x)
{
	if(i-j<=0)
	{
		t->A[j-i]=x;
	}
	else if(i-j>0)
	{
		t->A[4+i]=x;
	}
}
void display(Toeplitz t)
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(i-j==0)
			{
				cout<<t.A[0];
			}
			else if(i-j<0)
			{
				cout<<t.A[j-i];
			}
			else if(i-j>0)
			{
				cout<<t.A[4+i-j];
			}
		}
		cout<<"\n";
	}
}
int main()
{
	Toeplitz t;
	set(&t,0,0,1);
	set(&t,1,0,2);
	set(&t,2,0,3);
	set(&t,3,0,4);
	set(&t,4,0,5);
	set(&t,0,1,6);
	set(&t,0,2,7);
	set(&t,0,3,8);
	set(&t,0,4,9);
	display(t);
	return 0;
}
