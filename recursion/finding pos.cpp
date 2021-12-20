#include<iostream>
using namespace std;
int findpos(int *A,int size,int ele)
{
	//base case
	if(size == 0)
	{
		return -1;
	}
	if(ele == A[0])
	return 0;
	else
	{//Recursive call
		int pos = findpos(A+1,size-1,ele);
		//calculationu8
		if(pos == -1)
		return pos;
		else
		return pos +1;
	}
}
int main()
{
	cout<<"\nenter size of array\n";
	int n;
	cin>>n;
	int *A;
	A = new int[n];
	for(int i =0;i<n;i++)
	{
		cin>>A[i];
	}
	cout<<"Enter the element to be searched\n";
	int ele;
	cin>>ele;
	int pos;
	pos = findpos(A,n,ele);
	cout<<"Position of the element = "<<pos;
	return 0;
}