#include<iostream>
using namespace std;
void sort(int *arr,int p,int n,int i)
{
  if(i==n)
  {
    if(p==1)
    {
     cout<<"Not sorted"; 
    }
    else
    {
      cout<<"Sorted";
    }
    
  }
  else
  {
    if(arr[i]<arr[i-1])
    {
      p=1;
    }
    sort(arr,p,n,i+1);
    
  }
}
int main()
{
  cout<<"Enter size of array\n";
  int n;
  cin>>n;
  int *arr = new int[n];
  for(int i = 0;i<n;i++)
  {
    cin>>arr[i];
  }
  sort(arr,0,n,0);
  return 0;
}