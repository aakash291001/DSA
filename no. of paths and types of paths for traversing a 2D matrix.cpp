#include<iostream>
using namespace std;
int count=0;
void path(int n,int m,int i,int j,string str)
{
  if(i==n)
  {
    return;
  }
  else if(j==m)
  {
    return;
  }
  else if(i==n-1&&j==m-1)
  {
   count++;
    cout<<str<<"\n";
  }
  else
  {
    path(n,m,i+1,j,str+"D");
    path(n,m,i,j+1,str+"R");
  }
}
int main()
{
  cout<<"Enter no. of rows and columns\n";
  int n;
  int m;
  cin>>n;
  cin>>m;
  path(n,m,0,0," ");
  cout<<"no. of paths = "<<count;
  return 0;
}