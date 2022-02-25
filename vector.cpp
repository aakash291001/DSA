#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	for(int i = 0;i<v.size();i++)
	{
		cout<<v[i]<<"\n";
	}
	vector<int>::iterator it;
	for(it = v.begin();it!=v.end();it++)
	{
		cout<<"\n"<<*it;
	}
	v.pop_back();
	for(it = v.begin();it!=v.end();it++)
	{
		cout<<"\n"<<*it;
	}
	cout<<"\nSecond Vector\n";
	vector<int> v2(5,125);
	vector<int>::iterator it2;
	for(it2=v2.begin();it2!=v2.end();it2++)
	{
		cout<<"\n"<<*it2;
	}
	//Exchanging value of v and v2 using swap function
	swap(v,v2);
	cout<<"\nAfter swapping";
	for(it2=v2.begin();it2!=v2.end();it2++)
	{
		cout<<"\n"<<*it2;
	}
	return 0;
}