#include<iostream>
using namespace std;
void TOH(int n,char p,char q,char r)
{
	if(n==1)
	{
		cout<<"move "<<n<<" from "<<p<<" to "<<q<<"\n";
	}
	else
	{
		TOH(n-1,p,r,q);
		cout<<"move "<<n<<" from "<<p<<" to "<<q<<"\n";
		TOH(n-1,r,q,p);
	}
}
int main()
{
	TOH(3,'A','C','B');
	return 0;
}