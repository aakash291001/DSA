#include<iostream>
#include<unordered_map>
#include<string>-
using namespace std;
string removeDup(string str)
{
	string str2;
	unordered_map<char,int> ourMap;
	for(int i=0;i<str.length();i++)
	{
		ourMap[str[i]]++;
	}
	for(int i =0;i<str.length();i++)
	{
		if(ourMap[str[i]]>0)
		{
			str2+=str[i];
			ourMap[str[i]]=0;
		}
	}
	return str2; 
}
int main()
{
	unordered_map<string,string> ourmap;
	cout<<"Enter the string\n";
	string str;
	cin>>str;
	string newStr;
	newStr = removeDup(str);
	cout<<newStr;
	return 0;
}