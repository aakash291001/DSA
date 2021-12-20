#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> v;
	cout<<"\nCapacity= "<<v.capacity();
	cout<<"\nSize= "<<v.size();
	v.push_back(1);
	cout<<"\nCapacity= "<<v.capacity();
	cout<<"\nSize= "<<v.size();
	v.push_back(2);
	cout<<"\nCapacity= "<<v.capacity();
	cout<<"\nSize= "<<v.size();
	v.push_back(3);
	cout<<"\nCapacity= "<<v.capacity();
	cout<<"\nSize= "<<v.size();
	v.push_back(4);
	cout<<"\nCapacity= "<<v.capacity();
	cout<<"\nSize= "<<v.size();
	v.push_back(5);
	cout<<"\nCapacity= "<<v.capacity();
	cout<<"\nSize= "<<v.size();
	
	cout<<"\n3rd element = "<<v.at(2);
	cout<<"\nFirst element = "<<v.front();
	cout<<"\nLast element = "<<v.back();
	
	cout<<"\nBefore pop\n";
	for(int i:v)
	{
		cout<<i<<" ";
	}
	cout<<"\nAfter pop \n";
	v.pop_back();
	for(int i:v)
	{
		cout<<i<<" ";
	}
	//Creating a vector with same element 
	vector<int> a(5,1);
	cout<<"\nElement of a are\n";
	for(int i:a)
	{
		cout<<i<<" ";
	}
	//Copying a vector
	vector<int> b(a);
	cout<<"\nElement of b are\n";
	for(int i:b)
	{
		cout<<i<<" ";
	}
	return 0;
}