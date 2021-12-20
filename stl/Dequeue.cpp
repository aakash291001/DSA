#include<iostream>
#include<deque>
using namespace std;
int main()
{
	deque<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_front(3);
	a.push_front(4);
	for(int i:a)
	{
		cout<<i<<" ";
	}
	cout<<"\nSecond element="<<a.at(1);
	
	cout<<"\nFirst element = "<<a.front();
	cout<<"\nLast Element = "<<a.back();
	
	cout<<"\nempty or not = "<<a.empty();
	cout<<"\nSize of Double ended queue = "<<a.size();
	a.erase(a.begin());
	cout<<"\nafter deletion\n";
	for(int i:a)
	{
		cout<<i<<" ";
	}
//	a.erase(a.begin(),a.end());
//	cout<<"\nafter deletion\n";
//	for(int i:a)
//	{
//		cout<<i<<" ";
//	}
	return 0;
}