#include<iostream>
#include<string>
using namespace std;
int main()
{
	/*character array are static
	In character we need to know the size before.
	No need to know the size before.
	
	No Terminating extra character '\0' in character array
	Terminatinig charachter '\0' is required
	*/
//	cout<<"Enter a string\n";
//	string str;
//	cin>>str;//In this method after space letter will not be included
//	cout<<str;
//	//Ways of declaring sting//
//	string str2(5,'A');//Declaration at initialisation
//	cout<<str2;
//	string str3;
//	str3="VARSH A"; 
//	cout<<str3;
////	For spacing at the time of insertion
//	string str4;
//	getline(cin,str4);
//	string str5;
//	getline(cin,str5);
////	str4.append(str5);
//	cout<<"\n"<<str4+str5;
//	cout<<"\n"<<str5[2];
//	str4.clear();f
//	cout<<"\n"<<str4;
	string str6 = "abc";
	string str7 = "xyz";
	if(!str6.compare(str7))
	{
		cout<<"equal";
		}
	if(!str6.empty())
	{
		cout<<"\nNot empty";
		}
//	str6.erase(1,2);
	cout<<"\n"<<str6;	
	cout<<str6.find("ab");
	str6.insert(1,"BKC");
	cout<<"\n"<<str6;
	cout<<"\n"<<str6.size();
	string str8 = str6.substr(1,3);
	cout<<"\n"<<str8;
	string str9;
	int x = 200;
	string str10 = to_string(x);
	cout<<"\n"<<str10;
	int y = stoi(str10);
	cout<<"\n"<<str10;
	
	return 0;
}