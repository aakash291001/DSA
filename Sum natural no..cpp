#include<iostream>
using namespace std;
int sum(int n)
{
	
	int Sum;
	if(n>0)
    {
    Sum=n+sum(n-1);
	return Sum;
	}	
	else
	return 0;
	
}
int main()
{
	int n;
	cout<<"Enter the number"<<"\n";
	cin>>n;
	cout<<sum(n);
	return 0;
}
