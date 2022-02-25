#include<iostream>
using namespace std;
int main()
{
	int b[] = {1,2,4};
	cout<<b<<"\n";//contents for array of other data type
	char a[10] = {'a','b','c','\0'};
	cout<<a<<endl;//due to Operator overloading
	cout<<a+1<<endl;//due to Operator overloading
	return 0;
}