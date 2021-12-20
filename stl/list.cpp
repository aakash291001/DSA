#include<iostream>
#include<list>
using namespace std;
int main()
{
	list<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_front(10);
	a.push_front(20);
	cout<<"Elements are ";
	for(int i:a)
	{
		cout<<i<<" ";
	}
	a.pop_back();
	a.pop_front();
	cout<<"\nElements after deletion are ";
	for(int i:a)
	{
		cout<<i<<" ";
	}
	a.erase(a.begin());//here we cann't delete in range we have delete one by one
	cout<<"\nElements after deletion are ";
	for(int i:a)
	{
		cout<<i<<" ";
	}
	return 0;
}