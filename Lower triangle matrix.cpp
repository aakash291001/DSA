#include<iostream>
using namespace std;
struct Ltriangle
{
	int A[20];
	int n;
};
void set(Ltriangle *m,int r)
{
		for(int j=0;j<=r;j++)
		{
				int x;
			cout<<"input Row element";
			cin>>x;
			m->A[r*(r+1)/2 + j] = x;
		}
}
void disp(Ltriangle m)
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(j<=i)
			cout<<m.A[i*(i+1)/2 + j];
			else 
			cout<<0;
		}
		cout<<"\n";
	}
}
int main()
{
	Ltriangle m;
	set(&m,0);
	set(&m,1);
	set(&m,2);
	set(&m,3);
	set(&m,4);
	disp(m);
	return 0;
}
