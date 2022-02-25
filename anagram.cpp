#include<iostream>
#include<cstring>
using namespace std;
void anagram(char A[100],char B[100])
{
	if(strlen(A)==strlen(B))
	{
		int H[26]={0};
		for(int i=0;A[i]!='\0';i++)
		{
			H[A[i]-97]++;
		}
		for(int i=0;B[i]!='\0';i++)
		{
			H[B[i]-97]--;
		}
		int m=0;
	    for(int i=0;A[i]!='\0';i++)
	    {
	    	if(H[i]!=0)
	    	{
	    		m=1;
	    		break;
			}
			
		}
		if(m==0);
		{cout<<"Strings are anagram";		
		}else
		{cout<<"Strings are not anagram";
		}
		
	}
	else
	cout<<" These Strings are not anagram";
}
int main()
{
	char A[100],B[100];
	cout<<"enter first string\n";
	gets(A);
	cout<<"Enter second string\n";
	gets(B);
	anagram(A,B);
	return 0;
}
