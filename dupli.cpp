#include<iostream>
#include<cstring>
using namespace std;
void duplicates(char A[100])
{
	int l;
	l=A[0];
	for(int i=1;A[i]!='\0';i++)
	{
		if(A[i]>l)
		{
			l=A[i];
		}
	}
	int H[l-96];
	for(int i=0;i<l-96;i++)
	{
		H[i]=0;
	}
	for(int i=0;A[i]!='\0';i++)
	{
		H[A[i]-97]++;
	}
	for(int i=0;A[i]!='\0';i++)
	{
		if(H[i]>1)
		{
			cout<<A[i]<<" is repeated "<<H[i]<<" times";
		}
	}
}
int main()
{
	char A[100];
	cout<<"Enter a string only lowercase letters\n";
	gets(A);
	duplicates(A);
	return 0;
}
