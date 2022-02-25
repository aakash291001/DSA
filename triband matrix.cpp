#include<iostream>
using namespace std;
struct Trimatrix
{
	int A[20];
};
void set(Trimatrix *t,int i,int j,int x)
{
	if(i-j==1)
	{
		t->A[j]=x;
	}
	else if(i-j==0)
	{
		t->A[5 - 1 + j] = x;
	}
	else if(i-j==-1)
	{
		t->A[10 - 1 + i] = x;
	}
}
void display(Trimatrix t)
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(i-j==1)
			cout<<t.A[j];
			else if(i-j==0)
			cout<<t.A[5-1 + j];
			else if(i-j==-1)
			cout<<t.A[10 - 1 + i];
			else 
			cout<<0;
		}
		cout<<"\n";
	}
}
int main()
{
	Trimatrix t;
	set(&t,0,0,1);
	set(&t,1,1,1);
	set(&t,2,2,1);
	set(&t,3,3,1);
	set(&t,4,4,1);
	set(&t,0,1,3);
	set(&t,1,2,3);
	set(&t,2,3,3);
	set(&t,3,4,3);
	set(&t,1,0,3);
	set(&t,2,1,3);
	set(&t,3,2,3);
	set(&t,4,3,3);
	display(t);
	return 0;
}
