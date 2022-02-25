#include<iostream>
using namespace std;
struct array
{
	int A[20];
	int size;
	int length;
};
void duplicate2(array arr)
{
	int g;
	g=arr.A[0];
	for(int i=0;i<arr.length;i++)
	{
		if(g<arr.A[i])
		g=arr.A[i];
	}
	int B[g];
	for(int i=0;i<=g;i++)
	{
		B[i]=0;
	}
	for(int i=0;i<arr.length;i++)
	{
		B[arr.A[i]]++;
	}
	for(int i=1;i<=g;i++)
	{
		if(B[i]>1)
		cout<<i<<" is the duplicate no."<<"\n";
	}
}
int main()
{
	array arr{{3,6,8,8,10,12,15,15,15,20},20,10};
	return 0;
}
