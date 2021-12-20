#include<iostream>
#include<string>
using namespace std;
void remx(char word[])
{
  int s = strlen(word);
  if(s==0)
  {
  	return;
  }
  else
  {
  	if(word[0]=='x'||word[0]=='X')
  	{
  		if(s==1)
  		{
  			word[0]='\0';
  			return;
		  }
  		int i;
  		for(i = 1;i<s;i++)
  		{
  			word[i-1]=word[i];
		  } 
		  word[i+1]='\0';
		  remx(word);
	}
	else
	remx(word+1);
}
}
int main()
{
cout<<"Enter a word\n";
  char word[100];
  cin.getline(word,100);
  remx(word);
  cout<<"\n"<<word;
  return 0;	
}

             
           
