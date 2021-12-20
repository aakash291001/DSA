#include<iostream>
#include<string>
using namespace std;

void repie(char str[])
{
	int c = strlen(str);
	if(c==0||c==1)
	{
		return;
	}
	else
	{
				
		if(str[0]=='p'&&str[1]=='i')
		{
			for(int i=c+1;i>=2;i--)
			{
				str[i+1]=str[i-1];
			}		
//			for(int i=c+1;i>=2;i--)
//			{
//				str[i+2]=str[i];
//			}
			str[0]='3';
			str[1]='.';
			str[2]='1';
			str[3]='4';
		}
		repie(str+1);
	}
}
int main()
{
	cout<<"Enter the word\n";
	char p[100];
	cin.getline(p,100);
	repie(p);
	cout<<p;
	return 0;
}