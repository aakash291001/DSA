#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int cPair(vector<int> p,int k)
{
	unordered_map<int,int> map;
	for(int i=0;i<p.size();i++)
	{
		map[p[i]]++;
	}
	int pair=0;
	for(int i =0;i<p.size();i++)
	{
		if(map[p[i]]>0)
		{
			int p1=0,p2=0;
			if(map[p[i]-k]>0)
			{
				p1 = map[p[i]]*map[p[i]-k];
			}
			if(map[p[i]+k]>0)
			{
				p2 = map[p[i]]*map[p[i]+k];
			}
			map[p[i]]=0;
			map[p[i]+k]=map[p[i]-k]=0;
			pair+=p1+p2;
		}
	}
	return pair;
}
int main()
{
	cout<<"Enter size of array\n";
	int n;
	cin>>n;
	cout<<"Enter array elements\n";
	vector<int> A;
	for(int i=0;i<n;i++)
	{
		int p;
		cin>>p;
		A.push_back(p);
	}
	int diff;
	cout<<"Enter difference\n";
	cin>>diff;
	int count;
	count = cPair(A,diff);
	cout<<"No. of pairs are:"<<count;
	return 0;
}