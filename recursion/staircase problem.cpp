#include<iostream>
using namespace std;
int staircase(int n)
{
	if(n==1||n==0)
	{
		return 1;
	}
	if(n==2)
	{
		return 2;
	}
	else 
	{
		int sum = staircase(n-1)+staircase(n-2)+staircase(n-3);
		return sum;
	}	
}
int main()
{
	cout<<"Enter No. of stairs\n";
	int n;
	cin>>n;
	int w;
	w = staircase(n);cout<<"No. of ways = "<<w;
	return 0;
}