#include<iostream>
using namespace std;
struct Matrix 
{
	int A[5];
	int n;
};
void set(Matrix *m,int i, int j,int x)
{
	if(i==j)
	{
		m->A[i]=x;
	}
}
void display(Matrix m)
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(i==j)
			{
				cout<<m.A[i];
			}
			else 
			cout<<0;
		}
		cout<<"\n";
	}
}
int main()
{
	Matrix m;
	m.n = 4;
	set(&m,0,0,5);
	set(&m,1,1,5);
	set(&m,2,2,5);
	set(&m,3,3,5);
	set(&m,4,4,5);
	display(m);
	return 0;
	
}
