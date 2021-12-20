#include<iostream>
#include<queue>
using namespace std;
bool recHeap(int *a,int i,int s)
{
  int lchild,rchild;
  rchild = 2*i+2;
  lchild= 2*i+1;
  if(lchild>=s&&rchild>=s)
  return true;
  else
  {
    if(lchild<s&&rchild<s)
    {
      if(a[lchild]<a[i]&&a[rchild]<a[i])
      return recHeap(a,lchild,s)&&recHeap(a,rchild,s);
      else
      return false;
    }
    
    else if(lchild<s)
    {
      if((a[lchild]<a[i]))
      return recHeap(a,lchild,s);
      else
      return false;
    }
    else if(rchild<s)
    {
      if((a[rchild]<a[i]))
      return recHeap(a,rchild,s);
      else
      return false;
      
    }
    
  }
}
int main()
{
  int n;
  cout<<"Enter size\n";
  cin>>n;
  int *a;
  a = new int[n];
  cout<<"Enter array elements\n";
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  cout<<recHeap(a,0,n);
  return 0;
}