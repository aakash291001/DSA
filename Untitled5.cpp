#include<iostream>
using namespace std;
struct array 
{
	int A[20];
	int size;
	int length;
};
void Pair(array arr)
{
	int i,j;
	i=j=0;
	for(i=0;i<arr.length-1;i++)
	{
		for(j=i+1;j<arr.length;j++)
		{
			if(arr.A[i]+arr.A[j]==10&&arr.A[i]!=-1)
			{
				cout<<arr.A[i]<<"+"<<arr.A[j]<<"\n";
				arr.A[j]=-1;
			}
		}
	}
}
int main()
{
	array arr{{6,3,8,10,16,7,5,2,9,14},20,10};
	Pair(arr);
	return 0;
}
