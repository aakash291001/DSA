#include<iostream>
using namespace std;
void funB(int n);
void funA(int n)
{
	if(n>0)
	{cout<<n<<"\n";
	funB(n-1);
	}
	
}
void funB(int n)
{
	if(n>1)
	{cout<<n<<"\n";
	funA(n/2);
	}
	
}


int main()
{
	int a=20;
	funA(20);
	return 0;
}
