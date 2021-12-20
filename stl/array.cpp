#include<iostream>
#include<array>
using namespace std;
int main()
{
	int basic[4] = {1,2,3,4};
	array<int,4> b = {4,5,6,7};
	int s = b.size();
	for(int i = 0;i<s;i++)
	{
		cout<<b[i]<<" ";
	}
	cout<<"\nIs array empty or not = "<<b.empty();
	cout<<"\nFirst element "<<b.front();
	cout<<"\nLast element "<<b.back();
	cout<<"\n3rd element = "<<b.at(2);
	return 0;
}