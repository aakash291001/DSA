#include<iostream>
using namespace std;
void NOD(int n,int &p)
{
	if(n==0)
	{
		return;
	}
	p++;
	NOD(n/10,p);
}
int main()
{
	cout<<"enter No. of digits\n";
	int n;
	cin>>n;
	int p =0;
	NOD(n,p);
	cout<<"\nNo. of digits are = "<<p;
	return 0;
}