#include<iostream>
using namespace std;
int count_vowel(char A[10])
{int count;
	for(int i=0;A[i]!='\0';i++)
	{
		if(A[i]=='i'||A[i]=='I'||A[i]=='a'||A[i]=='A'||A[i]=='e'||A[i]=='E'||A[i]=='o'||A[i]=='O'||A[i]=='u'||A[i]=='U')
		{
			count++;
		}
	}
	return count;
}
int main()
{
	char A[10]; 
	cout<<"Enter a sentence\n";
	gets(A); 
	int no;
	no=count_vowel(A);
	cout<<"\nNo. of Vowel are"<<no;
	return 0;
}
