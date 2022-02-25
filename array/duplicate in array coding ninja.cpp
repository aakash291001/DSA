#include<iostream>
#include<algorithm>
using namespace std;
int twicFind(int A[],int n)
{
  int sum = 0;
  for(int i=0;i<n;i++)
  {
  	sum +=A[i];
  }
  int sum2 = (n-1)*(n-2)/2;
  return sum - sum2;
}
int main()
{
  int A[]={1,2,3,1,0};
  int twi=twicFind(A,5);
  cout<<"answer = "<<twi;
  return 0;
}