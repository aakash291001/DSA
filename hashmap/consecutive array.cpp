#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
pair<int,int> maxCon(int A[],int size)
{
	unordered_map<int,bool> record;
	for(int i =0;i<size;i++)
	{
		record[A[i]]=true;
	}
	int maxlength=1;
	int start=record[A[0]];
	for(int i =0;i<size;i++)
	{
		if(record[A[i]]==true)
		{
			int min = A[i];
			int len = 0;
			record[A[i]]=false;
			int m =1,n=1;
			while(record[A[i]-m]==true)
			{
				record[A[i]-m]=false;
				min = A[i]-m;
				m++;
				len++;
			}
			while(record[A[i]+n]==true)
			{
				record[A[i]+n]=false;
				n++;
				len++;
			}
			if(len>maxlength)
			{
				maxlength = len;
				start = min;
			}
		}
	}
	pair<int,int> pairA;
	pairA.first = start;
	pairA.second = start+maxlength;
	return pairA;
}
int main()
{
	cout<<"Enter the array size\n";
	int n;
	cin>>n;
	cout<<"Enter the arrray element\n";
	int *A;
	A = new int[n];
	for(int i = 0;i<n;i++)
	{
		cin>>A[i];
	}
	pair<int,int> AB;
	AB=maxCon(A,n);
	cout<<AB.first<<" "<<AB.second;
	return 0;
}
//Another 
//#include<iostream>
//#include<unordered_map>
//using namespace std;
//void longCons(int A[],int n)
//{
//  unordered_map<int,bool> mp;
//  for(int i=0;i<n;i++)
//  {
//    mp[A[i]]=true;
//  }
//  int start = A[0];
//  int length = 1;
//  int i=0;
//  while(i<n)
//  {
//    if(mp[A[i]]==true)
//    {
//      int length1=1;
//    int j = 1;
//    int small = A[i];
//    while(mp[A[i]+j]==true)
//    {
//      length1++;
//      mp[A[i]+j]=false;
//      j++;
//    }
//    j=1;
//    while(mp[A[i]-j]==true)
//    {
//      length1++;
//      small = A[i]-j;
//      mp[A[i]-j]=false;
//      j++;
//    }
//    if(length1>length)
//    {
//      length = length1;
//      start = small;
//    }
//      }
//    
//    i++;
//  }
//  for(int i=0;i<length;i++)
//  {
//    cout<<start<<" ";
//    start++;
//  }
//}
//int main()
//{
//  int A[]={2,12,9,16,10,5,3,20,25,11,1,8,6};
//  int n = 13;
//  longCons(A,n);
//  return 0;
//}