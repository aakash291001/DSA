#include<iostream>
#include<map>
using namespace std;
int main()
{
	map<string,string> m;
	m["AAKASH"] = "buggati";
	m["MADHAV"] = "lamborghini";
	m["SHIVAM"] = "mercerdies";
	for(auto i:m)
	{
		cout<<i.first<<" "<<i.second<<"\n";
	}
	cout<<" is buggati present "<<m.count("buggati");
	cout<<" is Aakash present "<<m.count("AAKASH");
	m.erase("SHIVAM");
	cout<<"\nAfter deletion\n";
	for(auto i:m)
	{
		cout<<i.first<<" "<<i.second<<"\n";
	}
	cout<<"\nAfter adding abhinav\n";
	m["ABHINAV"] = "AUDI";
	map<string,string>::iterator p = m.find("MADHAV");
	for(auto i = p;i!=m.end();i++)
	{
		cout<<(*i).first<<" "<<(*i).second<<"\n";
	}
 } 