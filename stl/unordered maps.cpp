#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
	unordered_map<string,int> ourmap;
	//insert
	pair<string,int> p("abc",1);
	ourmap.insert(p);
	ourmap["def"] = 2;
	//find or access
	cout<<ourmap["abc"]<<" ";
	cout<<ourmap.at("def")<<" ";
	cout<<"Size ="<<ourmap.size()<<"\n";
//	difference between at and []
//	if key is not there then at will stop the programme
//	and if we use [] then it will "Insert zero" at that index
//	ourmap.at("ghi") this will end the programme 
//	ourmap["ghi"] this will insert zero at this index
	cout<<ourmap["ghi"]<<" ";
	
//	check present
	if(ourmap.count("ghi")>0)
	cout<<"ghi is present\n";
	else
	cout<<"ghi is not present\n";
	cout<<"Size ="<<ourmap.size()<<"\n";
	//erase
	ourmap.erase("ghi");
	if(ourmap.count("ghi")>0)
	cout<<"ghi is present\n";
	else
	cout<<"ghi is not present\n";
	cout<<"Size ="<<ourmap.size()<<"\n";
	return 0;
}