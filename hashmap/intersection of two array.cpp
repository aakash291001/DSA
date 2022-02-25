#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
vector<int> intersection(int *A,int n,int *B,int m)
{
  int *arr1,*arr2;
  int size1,size2;
  if(n>=m)
  {
    arr1 = A;
    size1 = n;
    arr2 = B;
    size2 = m;
  }
  else
  {
    arr2 = A;
    size2 = n;
    arr1 = B;
    size1 = m;
  }
  unordered_map<int,pair<bool,bool>> map1;
  for(int i =0;i<size1;i++)
  {
    if(map1[arr1[i]].first==false)
    map1[arr1[i]].first=true;
  }
  for(int i =0;i<size2;i++)
  {
    if(map1[arr2[i]].second==false)
    map1[arr2[i]].second=true;
  }
  vector<int> a;
  unordered_map<int,pair<bool,bool>>::iterator it=map1.begin();
  while(it!=map1.end())
  {
    if(it->second.first==true&&it->second.second==true)
    a.push_back(it->first);
    it++;
  }
  return a;
}
int main()
{
  int A[]={10,10};
  int n= 2;
  int B[]={10};
  int m=1;
  vector<int> a;
  a=intersection(A,n,B,m);
  for(auto i=a.begin();i!=a.end();i++)
  {
    cout<<*i<<" ";
  }
  
  return 0;
}