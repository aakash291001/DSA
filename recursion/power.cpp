#include<iostream>
using namespace std;
int power1(int n,int p)
{
	if(p==1)
	return n;
	return n*power1(n,p-1);
}
int main()
{
	cout<<"Enter Base \n";
	int n;
	cin>>n;
	cout<<"ENter power\n";
	int p;
	cin>>p;
	int ans = power1(n,p);
	cout<<"\nAnswer = "<<ans;
	return 0;
}