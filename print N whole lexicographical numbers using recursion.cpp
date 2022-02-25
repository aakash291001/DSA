#include<iostream>
using namespace std;
void lex(int n,int str)
{
  if(str<=n)
  {
    cout<<str<<"\n";
  }
  else if(str>=n)
  {
    return;
  }
  if(str==0)
  {
    for(int i = 1;i<=9;i++)
  {
    lex(n,str*10 +i);
  }
  }
  else
  {
    for(int i = 0;i<=9;i++)
  {
    lex(n,str*10 +i);
  }
  }
  
}
int main()
{
  cout<<"enter max no.\n";
  int n;
  cin>>n;
  lex(n,0);
  return 0; 
}