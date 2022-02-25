#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int diffBInd(int A[],int n)
{
  unordered_map<int,vector<int>> map;
  for(int i=0;i<n;i++)
  {
    map[A[i]].push_back(i);
  }
  int minDiff=n+1;
  unordered_map<int,vector<int>>::iterator it = map.begin();
  while(it!=map.end())
  {
    if(it->second.size()>1)
    {
      if((it->second[1]-it->second[0])<minDiff)
      minDiff=it->second[1]-it->second[0];
    }
    it++;
  }
  if(minDiff==n+1)
  return -1;//return -1 if there is no repetetion
  return minDiff;
}
int main()
{
  int A[]={5,47,82,4,4,6,2};
  int n = 7;
  int min = diffBInd(A,n);
  cout<<min;
  return 0;
}