#include<iostream>
#include<vector>
using namespace std;
void swap(int *a,int *b)
{
  int x;
  x=*a;
  *a=*b;
  *b=x;
}
void sorti(vector<int> &pq,int size)
{
  if(size<=1)
  return;
  else
  {
    int p=0;
    int q=size-1;
    swap(&pq[p],&pq[q]);
    int lchild = 2*p+1;
    int rchild = 2*p+2;
    int main;
    if(lchild<q&&rchild<q)
    {
      if(pq[rchild]<pq[lchild])
      main=rchild;
      else
      main=lchild;
    }
    else if(lchild<q)
    {
      main = lchild;
    }
    else if(rchild<q)
    {
      main=rchild;
    }
    else
    return;
    while((pq[main]<pq[p])&&(rchild<q||lchild<q))
    {
      swap(&pq[p],&pq[main]);
      p=main;
      lchild=2*p+1;
      rchild=2*p+2;
      if(lchild<q&&rchild<q)
    {
      if(pq[rchild]<pq[lchild])
      main=rchild;
      else
      main=lchild;
    }
    else if(lchild<q)
    {
      main = lchild;
    }
    else if(rchild<q)
    {
      main=rchild;
    }
    }
    sorti(pq,size-1);
  }
}
int main()
{
  vector<int> vec;
  for(int i=0;i<5;i++)
  {
    int n;
    cin>>n;
    vec.push_back(n);
  }
  sorti(vec,vec.size());
  for(int i=0;i<5;i++)
  {
    cout<<vec[i]<<" ";
  }
  return 0;
}