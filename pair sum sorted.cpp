#include<iostream>
using namespace std;
struct array 
{
	int A[20];
	int size;
	int length;
};
void pair_sum(array arr)
{
	for(int i=0;i<arr.length-1;i++)
	{
		for(int j=arr.length-1;j!=i;j--)
		{
			if(arr.A[i]+arr.A[j]==10)
			{
				cout<<"Pair is"<<arr.A[i]<<"+"<<arr.A[j]<<"=10"<<"\n";
			}
		}
	}
}
void pair_sum2(array arr)
{
	for(int i=0,j=arr.length-1;i<j;)
	{
		if(arr.A[i]+arr.A[j]==10)
		{
			cout<<"Pair is"<<arr.A[i]<<"+"<<arr.A[j]<<"=10"<<"\n";
			i++;j--;
		}
		else if(arr.A[i]+arr.A[j]<10)
		{
			i++;
		}
		else
		j--;
	}
}
int main()
{
	array arr{{1,3,4,5,6,8,9,10,12,14},20,10};
	pair_sum2(arr);
	return 0;
}
