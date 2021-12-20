#include<iostream>
#include<string.h>
using namespace std;
bool checkp(string A,int s,int e)
{
	if(e-s<=1)
	return true;
	else
	{
		if(A[s]==A[e])
		return checkp(A,s+1,e-1);
		else
		return false;
	}
}
int main()
{
	cout<<"Enter a string\n";
	string A;
	cin>>A;
	int s;
	s = A.size();
//	cout<<s;
	bool res;
	res = checkp(A,0,s-1);
	cout<<"Result is "<<res;
	return 0;
}