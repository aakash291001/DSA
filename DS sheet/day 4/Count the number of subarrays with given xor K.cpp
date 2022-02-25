#include<bits/stdc++.h>
using namespace std;
int countXor(int A[],int n,int B)
{
	int count=0;
	for(int i=0;i<n;i++)
	{
		int temp = A[i];
		if(temp == B)
		count++;
		for(int j=i+1;j<n;j++)
		{
			temp = temp^A[j];
			if(temp==B)
			count++;
		}
	}
	return count;
}
int countXor2(int A[],int n,int B)
{
	int tCount=0;
	unordered_map<int,int> ump;
	int x=0;
	for(int i=0;i<n;i++)
	{
		x=x^A[i];
		ump[x]++;
		if(x==B)
		tCount++;
		if(ump.find(x^B)!=ump.end())
		{
			tCount+=ump[x^B];
		}
	}
	return tCount;
}
int main()
{
	int A[] = {4, 2, 2, 6, 4};
	int n = sizeof(A)/sizeof(int);
	cout<<countXor2(A,n,6);
	return 0;
}