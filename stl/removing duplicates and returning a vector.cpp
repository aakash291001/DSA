#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
vector<int> removeDuplicate(int *a,int size)
{
	vector<int> output;
	unordered_map<int,bool> seen;//<key,value>
	for(int i=0;i<size;i++)
	{
		if(seen.count(a[i])>0)
		continue;//The continue statement breaks one iteration (in the loop), if a specified condition occurs, and continues with the next iteration in the loop.
		seen[a[i]]=true;
		output.push_back(a[i]);
	}
	return output;
}
int main()
{
	int a[]={1,2,3,2,1,5,4,1,3};
	vector<int> b;
	b = removeDuplicate(a,sizeof(a)/sizeof(int));
	for(int i:b)
	{
		cout<<i<<" ";
	}
	return 0;
}