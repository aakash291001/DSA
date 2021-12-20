#include<iostream>
#include<queue>
using namespace std;
int main()
{
	priority_queue<int> maxh;
	priority_queue<int,vector<int>,greater<int>> minh;
	maxh.push(0);
	maxh.push(4);
	maxh.push(3);
	maxh.push(2);
	maxh.push(1);
	int n;
	n = maxh.size();
	for(int i =0;i<n;i++)
	{
		cout<<maxh.top()<<" ";
		maxh.pop();
	}
	minh.push(0);
	minh.push(4);
	minh.push(3);
	minh.push(2);
	minh.push(1);
	int m;
	m = minh.size();
	for(int i =0;i<n;i++)
	{
		cout<<minh.top()<<" ";
		minh.pop();
	}
	cout<<"IS min heap empty ="<<minh.empty();
	return 0;
}