#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main()
{
	unordered_map<string,int> ourmap;
	ourmap["abc"] = 1;
	ourmap["abc1"] = 2;
	ourmap["abc2"] = 3;
	ourmap["abc3"] = 4;
	ourmap["abc4"] = 5;
	ourmap["abc5"] = 6;
	unordered_map<string,int>::iterator it=ourmap.begin();
	while(it!=ourmap.end())
	{
		cout<<"key :"<<it->first<<" Value :"<<it->second<<"\n";
		it++;
	}
	unordered_map<string,int>::iterator it2 = ourmap.find("abc");
//	ourmap.erase(it2);
//	THE Above statement will delete singal element
//	ourmap.erase(it2,it2+3)
//	the above statment will delete it2,it2+1,it2+2
	ourmap.erase(it2);
	unordered_map<string,int>::iterator it3=ourmap.begin();
	cout<<"After deletion\n";
	while(it3!=ourmap.end())
	{
		cout<<"key :"<<it3->first<<" Value :"<<it3->second<<"\n";
		it3++;
	}
	return 0;
}