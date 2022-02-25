#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int stoi(string str,int i,int n)
{
  if(i<n)
  return stoi(str,i+1,n)+(str.compare(i,1,"0")*pow(10,n-1-i));
  else
  return 0;
}
int main()
{
  cout<<"Enter the string\n";
  string str;
  getline(cin,str);
  int p = stoi(str,0,str.size());
  cout<<p;
  return 0;
}