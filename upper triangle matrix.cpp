#include<iostream>
using namespace std;
struct Utriangle
{
	int A[15];
	int n;
};
void set(Utriangle *u,int r)
{
	u->n=5;
	for(int i=r;i<=4;i++)
	{
		int x;
		cout<<"enter the no. ";
		cin>>x;
		u->A[r*(2*u->n-(r-1))/2+(i-r)]=x;
	}
}
void disp(Utriangle u)
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(j>=i)
			{
				cout<<u.A[i*(2*u.n-(i-1))/2+(j-i)];
			}
			else 
			cout<<0;
		}
		cout<<"\n";
	}
}
int main()
{
	Utriangle u;
	set(&u,0);
	set(&u,1);
	set(&u,2);
	set(&u,3);
	set(&u,4);
	disp(u);
	return 0;
}
