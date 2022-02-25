#include<bits/stdc++.h>
using namespace std;
int longSubZ(int A[],int n)
{
	int maxLen=-1;
	for(int i=0;i<n;i++)
	{
		int sum = A[i];
		for(int j=i+1;j<n;j++)
		{
			sum+=A[j];
			if(sum==0)
			{
				if(maxLen<j-i+1)
				maxLen=j-i+1;
			}
		}
	}
	return maxLen;
}
int longSubZ2(int A[],int n)
{
	int sum = 0;
	int maxLen = 0;
	unordered_map<int,int> ump;
	for(int i=0;i<n;i++)
	{
		sum+=A[i];
		if(sum==0)
		{
			maxLen = i+1;
		}
		else
		{
			if(ump.find(sum)!=ump.end())
			{
				maxLen = max(maxLen,i-ump[sum]);
			}
			else
			ump[sum] = i;
		}
	}
	return maxLen;
}
int main()
{
	int A[] = {6, -2, 2, -8, 1, 7, 4, -10};
	int n = sizeof(A)/sizeof(int);
	cout<<longSubZ2(A,n);
	return 0;
}