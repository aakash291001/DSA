#include<iostream>
using namespace std;
int main()
{
	int *q[3];
	q[0]=new int[4];
	q[1]=new int[4];
	q[2]=new int[4];
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<4;j++)
		{
			q[i][j]=i+j;
		}
	} 
	cout<<q[1][1]<<"\n";
	int **r;
	r=new int*[3];
	r[0]=new int[3];
	r[1]=new int[3];
	r[2]=new int[3];
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			r[i][j]=i+j;
		}
	} 
	cout<<r[2][2]<<"\n";
	int p[10][10];
	p[9][5]=100;
	cout<<p[9][5];
	return 0;
}
