#include<iostream>
using namespace std;
int main()
{
	char A[] = "java";
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
	for(int i=0;A[i]!='\0';i++)
	{
		cout<<A[i];
	}
	return 0;
}
