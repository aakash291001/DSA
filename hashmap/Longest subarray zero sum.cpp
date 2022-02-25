#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int findSum0(vector<int> A)
{
	int *arr;
	arr=new int[A.size()];
	arr[0]=A[0];
	int size;
	size = A.size();
	for(int i=1;i<size;i++)
	{
		arr[i]=arr[i-1]+A[i];
	}
//	for(int i =0;i<size;i++)
//	{
//		cout<<arr[i];
//	}
	int maxDiff = 0;
	unordered_map<int,vector<int>> map;
	for(int i=0;i<size;i++)
	{
		map[arr[i]].push_back(i);
	}
	for(int i=0;i<size;i++)
	{
		if(map[arr[i]].size()>1)
		{
			vector<int>::iterator it1,it2;
			it1 = map[arr[i]].begin();
			it2 = map[arr[i]].end();
			if(maxDiff<=(*(it2-1)-*it1))
			maxDiff=(*(it2-1)-*it1);
		}
	}
	return maxDiff;
}

int main()
{
	cout<<"Enter the size of array\n";
	int n;
	cin>>n;
	cout<<"Enter the elements of array\n";
	vector<int> arr;
	for(int i=0;i<n;i++)
	{
		int p;
		cin>>p;
		arr.push_back(p);
	}
	int maxDiff = findSum0(arr)+1;
	cout<<maxDiff;
	return 0;
}