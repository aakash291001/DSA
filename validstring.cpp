#include<iostream>
using namespace std;
int valids(char *A)
{
	int s;
	for(int i=0;A[i]!='\0';i++)
	{
		if((A[i]<=65&&A[i]>=90)||(A[i]<=97&&A[i>=122])||(A[i]<=48&&A[i]>=57))
		{
			s=0;
		}
	}
	return s;
}
int main()
{
	char *A="Computere1234";
	int s;
	s=valids(A);
	if(s==0)
	{
		cout<<"string is not valid";
	}
	else 
	{
		cout<<"string is valid";
	}
	return 0;
}
