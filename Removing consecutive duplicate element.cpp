#include<iostream>
#include<string>
using namespace std;
void findup(string str,int i,int n)
{
  if(i==0)
  {
    cout<<str[i];
    return;
  }
  
  findup(str,i-1,n);
  if(str[i]!=str[i-1])
  {
    cout<<str[i];
  }
  else
  return;
}
int main()
{
  cout<<"Enter String\n";
  string str;
  getline(cin,str);
  findup(str,str.size()-1,str.size());
  return 0;
}