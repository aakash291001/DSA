#include<iostream>
#include<string>
using namespace std;
int main()
{
  cout<<"Enter the no. of strings you want to enter\n";
  int n;
  cin>>n;
  string s[100];
  for(int i=0;i<n;i++)
  {
    getline(cin,s[i]);
  }
  for(int i=0;i<n;i++)
  {
    cout<<s[i]<<"\n";
  }
  return 0;
}