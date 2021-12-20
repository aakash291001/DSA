#include<iostream>
#include<queue>
//<priority_queue<>->maxheap
//isempty->empty()
//getSize()->size()
//void input(ele)->void push(ele)
//getMin->t top()
//T removeMin()-> void pop()
using namespace std;
int main()
{
	priority_queue<int> pq;
	pq.push(10);
	pq.push(100);
	pq.push(167);
	pq.push(7);
	pq.push(45);
	pq.push(32);
	cout<<"size :"<<pq.size()<<"\n";
	cout<<"Top :"<<pq.top()<<"\n";
	while(pq.size()!=0)
	{
		cout<<pq.top()<<" ";
		pq.pop();
	}
	return 0;
}