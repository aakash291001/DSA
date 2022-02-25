#include<iostream>
using namespace std;
void counts(char *A)
{
	int count=0;
	for(int i=0;A[i]!='\0';i++)
	{
		if(A[i]==' '&&A[i-1]!=' ')
		count++;
	}
	cout<<"The number of spaces are "<<count;

}
void countw(char *A)
{
	int count=0;
	for(int i=0;A[i]!='\0';i++)
	{
		if(A[i]==' '&&A[i-1]!=' ')
		count++;
	}
	cout<<"\n Number of words are "<<++count;
}
void countvc(char *A)
{
	int count1,count2;
	count1=count2=0;
	for(int i=0;A[i]!='\0';i++)
	{
		if(A[i]=='a'||A[i]=='A'||A[i]=='e'||A[i]=='E'||A[i]=='o'||A[i]=='O'||A[i]=='i'||A[i]=='I'||A[i]=='u'||A[i]=='U')
		{
			count1++;
		}
		else if((A[i]>=65&&A[i]<=90)||(A[i]>=97&&A[i]<=122))
		{
			count2++;
		}
		
	}
	cout<<"\nThe number of vowels are "<<count1;
	cout<<"\nThe number of consonants are"<< count2;
}
int main()
{
	char A[]="How are you";
	counts(A);
	countw(A);
	countvc(A);
	return 0;
}
