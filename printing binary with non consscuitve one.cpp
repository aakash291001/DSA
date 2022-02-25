#include<iostream>
using namespace std;
void bstring(int n,int p,string str1)
{
  if(n==p)
  {
    cout<<str1<<" "<<"\n";
   return;
  }
  char a=str1.at( n- 1 );
  if(a=='0')
  {
    bstring(n+1,p,str1+to_string(0));
    bstring(n+1,p,str1+to_string(1));
  }
  else
  {
    bstring(n+1,p,str1+to_string(0));
  }
}
int main()
{
  cout<<"Enter no. of bits\n";
  int n;
  cin>>n;
  bstring(1,n,"0");
  bstring(1,n,"1");
  return 0;
}