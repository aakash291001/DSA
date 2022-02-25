#include<iostream>
#include<vector>
using namespace std;
int uniqueEle(vector<int> vec)
{
  int s;
  s = vec.size();
  if(s == 1)
  return vec[0];
  else
  {
    int un=vec[0]^vec[1];
  for(int i=2;i<s;i++)
  {
    un = un^vec[i];
  }
  return un;
  }
  
}
int main()
{
  vector<int> vec;
  cout<<"Enter size of array\n";
  int n;
  cin>>n;
  cout<<"Enter elements\n";
  for(int i=0;i<n;i++)
  {
    int p;
    cin>>p;
    vec.push_back(p);
  }
  int out = uniqueEle(vec);
  cout<<"Answer = "<<out;
  return 0;
}