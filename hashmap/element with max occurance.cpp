#include<iostream>
#include<unordered_map>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int countMax(int arr[],int n)
{
	unordered_map<int,int> map;
	int max=0;int p;
	for(int i =0;i<n;i++)
	{
		map[arr[i]]++;
	}
	unordered_map<int,int>::iterator it=map.begin();
//	sort(a.end(),a.begin());
	int i=0;
	while(it!=map.end())
	{
		if(max<it->second)
		{
			max=it->second;
			p = it->first;
		}
		it++;
	}
	return p;
}
int main()
{
	int A[]={32,14,14,76,14,32,29,32};
	int n=9;
	int k = 4;
	int max =countMax(A,n);
	cout<<max;
	return 0;
}