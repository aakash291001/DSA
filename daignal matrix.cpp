#include<iostream>
using namespace std; 
struct matrix
{
	int A[5];
	int m;
};
void set(struct matrix *m ,int i,int j,int x)
{
	if(i==j)
	{
		m->A[i]=x;
	}
	else 
	m->A[i]=0;
}
void disp(matrix m)
{
	int i,j;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(i==j)
			printf("%d",&m.A[i]);
			else
			printf("0");
		}
		printf("\n");
	}
}
int main()
{
	matrix m;
	set(&m,0,0,1);
	set(&m,1,1,2);
	set(&m,2,2,3);
	set(&m,3,3,4);
	set(&m,4,4,5);
	disp(m);
	return 0;
}
