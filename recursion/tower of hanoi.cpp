#include<iostream>
using namespace std;
void TOH(int n,char i,char m,char f)
{
  if(n==1)
  {
    cout<<i<<" "<<f<<"\n";
  }
  else
  {
    TOH(n-1,i,f,m);
    cout<<i<<" "<<f<<"\n";
    TOH(n-1,m,i,f);
  }
}
int main()
{
  cout<<"Enter no. of disks\n";
  int n;
  cin>>n;
  TOH(n,'A','B','C');
  return 0;
}