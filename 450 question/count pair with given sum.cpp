#include<iostream>
using namespace std;
void insert(int *a,int n)
{
	for(int i =0;i<n;i++)
	{
		cin>>a[i];
	}
}
int getPairsCount(int a[],int n,int p)
{
  int i,j,k;
  int count=0;
  for(k=0;k<n-1;k++)
  {
    i=k+1;
    j=n-1;
    while(i<=j)
    {
      if(i<j)
      {
        if(a[i]+a[k]==p)
        {
          count++;
        }
        if(a[j]+a[k]==p)
        {
          count++;
        }
         
      }
      else
      {
        if(a[i]+a[k]==p)
        {
          count++;
        }
        
      }
      i++;
      j--;
    }
  }
  return count;
}
int main()
{
	int n;
	int p;
	cin>>n;
	cin>>p;
	int *a;
	a = new int[n];
	insert(a,n);
	cout<<"answer is"<<" "<<getPairsCount(a,n,p);
	return 0;
}