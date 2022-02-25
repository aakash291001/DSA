#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int count(int *a,int m)
{
  unordered_map<int,int> arr;
  for(int i =0;i<m;i++)
  {
    arr[a[i]]++;
  }
  int c=0;
  for(int i = 0;i<m;i++)
  {
    if(arr[a[i]]>=0&&arr[-a[i]]>=0)
    {
      if(arr[a[i]]==1&&arr[-a[i]]==1)
      {
        c++;
        arr[a[i]]=arr[-a[i]]=0;
      }
      else if(arr[a[i]]==1)
      {
        c=c+arr[-a[i]];
        arr[a[i]]=arr[-a[i]]=0;
      }
      else if(arr[-a[i]]==1)
      {
        c=c+arr[a[i]];
        arr[a[i]]=arr[-a[i]]=0;
      }
      else
      {
        c=c+arr[a[i]]+arr[-a[i]];
        arr[a[i]]=arr[-a[i]]=0;
      }
    }
  }
  return c;
}
int main()
{
  int A[]={2,1,-2,2,3};
  cout<<"No. of pairs are "<<count(A,sizeof(A)/sizeof(int));
  return 0;
}