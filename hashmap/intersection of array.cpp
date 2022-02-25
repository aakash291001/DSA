#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
vector<int> intersection(int *a,int m,int *b,int n)
{
  unordered_map<int,bool> one,two;
  vector<int> inter;
  for(int i=0;i<m;i++)
  {
    one[a[i]]=true;
  }
  for(int i=0;i<n;i++)
  {
    two[b[i]]=true;
  }
  int *c,m1;
  if(m<=n)
  {
    c = a;
    m1=m;
  }
  else
  {
    m1=n;
    c = b;
  }
  for(int i=0;i<m1;i++)
  {
    if(one[c[i]]==true&&two[c[i]]==true)
    {
		inter.push_back(c[i]);
		one[c[i]]=two[c[i]]==false;//so that repeated element not count again and again	
	}
  }
  return inter;
}

int main()
{
  int A[]={2,6,8,5,4,3};
  int As=6,Bs=4;
  int B[]={2,3,4,7};
  vector<int> b;
  b=intersection(A,As,B,Bs);
  for(int i:b)
  cout<<i<<" ";
  return 0;
}