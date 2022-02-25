#include<iostream>
using namespace std;
struct array 
{
	int A[20];
	int size;
	int length;
};
void sum(array arr)
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
	for(int i=0;i<arr.length;i++)
	{
		if(B[10-arr.A[i]]!=0)
		{
			cout<<"Pair is "<<10-arr.A[i]<<"&"<<arr.A[i]<<"\n";
		}
		B[arr.A[i]]++;
	} 
}
int main()
{
	array arr{{6,3,8,10,16,7,5,2,9,14},20,10}; 
	sum(arr);
	return 0;
}
