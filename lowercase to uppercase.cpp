#include<iostream>
using namespace std;
int main()
{
	char A[10] = "welcome";
	for(int i=0;A[i]!='\0';i++)
	{
		A[i]=A[i]-32;
	}
	puts(A);
	return 0;
}
