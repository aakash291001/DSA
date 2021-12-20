#include<iostream>
#include<queue>
using namespace std;
int main()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	cout<<"first Element is "<<q.front();
	cout<<"\nLast element is "<<q.back();
	q.pop();
	cout<<"\nfirst Element is "<<q.front();
	cout<<"\nLast element is "<<q.back();
	return 0;
}