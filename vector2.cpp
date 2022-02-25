#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> vec1;//One way of declaring variable
	vector<char> vect2;//character vector
	vect2.push_back('x');
	cout<<vect2.at(0);
	//3rd example of vector
	vector<char> vect3(vect2);//4 element from vector 2
	cout<<vect3.at(0);
	//4th example of vector
	vector<int> vect4(100,69);
	for(int i =0;i<vect4.size();i++)
	{
		cout<<" ";
		cout<<vect4.at(i);
	}
	for(int i = 0;i<4;i++)
	{
		int ele;
		cin>>ele;
		vec1.push_back(ele);
	}
	for(int i =0;i<vec1.size();i++)
	{
		cout<<vec1.at(i);
	}
	
	vector<int>::iterator iter = vec1.begin();
	
	vec1.insert(iter,69);
	for(int i =0;i<vec1.size();i++)
	{
		cout<<"\n";
		cout<<vec1.at(i);
	}
	return 0;
}