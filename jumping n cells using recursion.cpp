#include<iostream>
using namespace std;
int count=0;
void jump(int n,int i,int j,string str)
{
  if(i>n-1)
  {
    return;
  }
  else if(i==n-1)
  {
    count++;
    cout<<str<<"\n";
    return;
  }
  
    jump(n,i+1,1,str+to_string(1)+"->");
    jump(n,i+2,2,str+to_string(2)+"->");
    jump(n,i+3,3,str+to_string(3)+"->");
    jump(n,i+4,4,str+to_string(4)+"->");
    jump(n,i+5,5,str+to_string(5)+"->");
    jump(n,i+6,6,str+to_string(6)+"->");
  
}
int main()
{
  cout<<"Enter no. of cells\n";//in this program we are initially at 1
  int n;
  cin>>n;
  jump(n,0,0," ");
  cout<<"\n"<<count;
  return 0;
}