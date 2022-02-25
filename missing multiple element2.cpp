#include<iostream>
using namespace std;
struct array
{
	int A[20];
	int size;
	int length;
};
void missele(array arr)
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
		if(B[i]==0)
		{
			cout<<"Missing Element "<<g<<" "<<i<<"\n";
		}
	}
}

int main()
{
	array arr{{3,7,4,9,12,6,1,11,2,10},20,10};
	missele(arr);
	return 0;
}

