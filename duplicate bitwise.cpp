#include<iostream>
using namespace std;
int main()
{
	char A[100];
	cout<<"Enter a string in lowercase\n";
	gets(A);
	int H,x;
	H=x=0;
	for(int i=0;A[i]!='\0';i++)
	{
		x=1;
		x=x<<A[i]-97;
		if(x&&H>0)
		{
			cout<<A[i]<<" is repeat\n";
		}
		else
		H=x||H;
	}
	return 0;
}
