#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int checkDel(string str1,string str2)
{
	unordered_map<int,pair<int,int>> map;
	for(int i=0;i<str1.length();i++)
	{
		map[str1[i]].first++;
	}
	for(int i=0;i<str2.length();i++)
	{
		map[str2[i]].second++;
	}
	int count=0;
	unordered_map<int,pair<int,int>>::iterator it=map.begin();
	while(it!=map.end())
	{
		if(it->second.first!=it->second.second)
		count++;
		it++;
	}
	return count;
}
int main()
{
	string str1,str2;
	str1="aab";
	str2="aba";
	int dele = checkDel(str1,str2);
	cout<<dele;
	return 0;
}