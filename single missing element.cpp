#include<iostream>
using namespace std;
struct array
{
	int A[20];
	int size;
	int length;
};
missele(array arr)
{
	int miss;
	int diff;
	diff=arr.A[0];
	for(int i=0;i<arr.length;i++)
	{
		if(arr.A[i]-i!=diff)
		{
			cout<<"element is missing"<<"\n";
			cout<<"Missing element is "<<i+diff;
			break;
		}
	}
}
int main()
{
	array arr{{1,2,3,4,6,7,8},20,7};
	missele(arr);
	return 0;
}
