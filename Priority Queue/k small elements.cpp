#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> kSmall(int *a,int n,int k)
{
	priority_queue<int> pq;
	for(int i=0;i<k;i++)
	{
		pq.push(a[i]);
	}
	int i=k;
	while(i<n)
	{
		pq.push(a[i]);
		pq.pop();
		i++;
	}
	vector<int> vec;
	while(pq.size()!=0)
	{
		vec.push_back(pq.top());
		pq.pop();
	}
	return vec;
}
int main()
{
	int n=8;
	int *a;
	a = new int[8];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int k=4;
	vector<int> p = kSmall(a,n,k);
	for(int i=0;i<k;i++)
	cout<<p[i]<<" ";
	return 0;
}