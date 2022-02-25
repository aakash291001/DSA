#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char A[]="python";
	char B[6];
	strcpy(B,A);
	for(int i=0;B[i]!='\0';i++)
	{
		cout<<B[i];
	}
	int n=0;
	for(int i=0;A[i]!='\0';i++)
	{
		n++;
	}
	int i,j;
	for(i=0,j=n-1;i<=(n-1)/2;j--,i++)
	{
		int temp;
		temp = A[i];
		A[i]=A[j];
		A[j]=temp;
	}
	int m;
	m=strcmp(A,B);
	if(m==0)
	{
		cout<<"\nString is pallindrome";
	}
	else
	{
		cout<<"\nString is not pallindrome";
	}
	return 0;
}
