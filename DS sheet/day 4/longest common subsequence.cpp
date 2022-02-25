#include<bits/stdc++.h>
using namespace std;
int longConSeq(int A[],int n)
{
	sort(A,A+n);
	int maxLen = 1;
	int currLen=1;
	for(int i=1;i<n;i++)
	{
		if(A[i]-A[i-1]==1)
		{
			currLen++;
		}
		else
		{
			if(currLen>maxLen)
			{
				maxLen=currLen;
			}
			currLen=1;
		}
	}
	if(currLen>maxLen)
	{
		maxLen=currLen;
	}
	return maxLen;
}
int longConSeq2(int A[],int n)
{
	set<int> se;
    if(n==0)
        return 0;
	for(int i=0;i<n;i++)
	{
		se.insert(A[i]);
	}
	int maxLen = 1;
	int currLen=1;
	auto it = se.begin();
	int prev=*it;
	it++;
	while(it!=se.end())
	{
		int now= *it;
		if(now - prev==1)
		{
			currLen++;
			prev=*it;
		}
		else
		{
			if(maxLen<currLen)
			maxLen=currLen;
			currLen=1;
			prev=*it;
		}
		prev = *it;
		it++;
	}
	if(currLen>maxLen)
	{
		maxLen=currLen;
	}
	return maxLen;
}
int main()
{
	int A[] = {100, 200, 1, 3, 2, 4};
	int n = sizeof(A)/sizeof(int);
	 cout<<longConSeq2(A,n);
	return 0;
}