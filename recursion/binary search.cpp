#include<iostream>
using namespace std;
int Bsearch(int *A,int ele,int l,int h)
{
	if(l>h)
	{
		return -1;
	}
	else
	{
		int m = (l+h)/2;
		if(A[m]==ele)
		{
			return m;
		}
		else if(ele<A[m])
		{
			Bsearch(A,ele,l,m-1);
		}
		else
		{
			Bsearch(A,ele,m+1,h);
		}
	}
}
int main()
{
	cout<<"Enter the size of array\n";
	int n;
	cin>>n;
	cout<<"Enter the elements of array\n";
	int *A;
	A = new int[n];
	for(int i = 0;i<n;i++)
	{
		cin>>A[i];
	}
	cout<<"Enter the element to be searched\n";
	int ele;
	cin>>ele;
	int pos;
	pos=Bsearch(A,ele,0,n-1);
	cout<<"Position of the element is "<<pos;
	return 0;
}