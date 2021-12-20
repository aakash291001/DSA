#include<iostream>
#include<set>
using namespace std;
int main()
{
	set<int> s;
	s.insert(2);
	s.insert(1);
	s.insert(2);
	s.insert(0);
	s.insert(1);
	s.insert(1);
	s.insert(3);
	for(auto i:s)
	{
		cout<<i<<" ";
	}
	cout<<"\nAfter deletion\n";
	s.erase(s.begin());
	for(auto i:s)
	{
		cout<<i<<" ";
	}
	set<int>::iterator it = s.begin();
	it++;
	cout<<"\nAfter deletion\n";
	s.erase(it);
	for(auto i:s)
	{
		cout<<i<<" ";
	}
	cout<<"\n is 3 present "<<s.count(3);
	s.insert(10);
	cout<<"\n";
	set<int>::iterator mt = s.find(1);
	for(auto p = mt;p!=s.end();p++)
	{
		cout<<*p<<" ";
	}
	return 0;
}