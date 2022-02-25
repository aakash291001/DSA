#include<iostream>
using namespace std;
void duplicate(char A[100])
{
	for(int i = 0;A[i]!='\0';i++)
	{
		int count = 1;
		if((A[i]>=97&&A[i]<=122)||A[i]>=65&&A[i]<=90)
		{
			for(int j=i+1;A[j]!='\0';j++)
			{
				if(A[i]==A[j])
				{
					A[j]='0';
					count++;
				}
			}
			if(count>1)
			{
	     		cout<<A[i]<<"Appears "<<count<<"times\n";
			}
		}
	}
}
int main()
{
	char A[100];
	cout<<"Enter a string\n";
	gets(A);
	duplicate(A);
	return 0;
}
