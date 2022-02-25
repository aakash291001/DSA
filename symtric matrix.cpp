#include<iostream>
using namespace std;
struct Smatrix
{
	int A[5];
	int n;
};
void set(Smatrix *s,int i,int j,int x)
{
	for(int i=0;i<5;i++)
	{
		if(i==j)
		{
			s->A[i]=x;
		}
	}
}
void display(Smatrix s)
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(i<=j)
			{
				cout<<s.A[i];
			}
			else
			cout<<s.A[j];
		}
		cout<<"\n";
	}
}
int main()
{
	Smatrix s;
	set(&s,0,0,2);
	set(&s,1,1,3);
	set(&s,2,2,4);
	set(&s,3,3,5);
	set(&s,4,4,6);	
	display(s);
	return 0;
}
