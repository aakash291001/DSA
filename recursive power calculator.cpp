#include<iostream>
using namespace std;
int power(int a,int b)
{
  if(b==1)
  {
    return a;
  }
  else
  {
    if(b%2==0)
    {
      int temp = power(a,b/2);
      return temp*temp;
    }
    else
    {
      int temp = power(a,(b-1)/2);
      return a*temp*temp;
    }
  }
}
int main()
{
  int a;
  int b;
  std::cout << "enter the value of a and b" << std::endl;
  cin>>a>>b;
  cout<<"Answer is ="<<power(a,b);
  return 0;
}