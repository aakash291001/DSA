#include<iostream>
#include<stack>
using namespace std;
int main()
{
	stack<string> s;
	s.push("Aakash");
	s.push("Shivam");
	s.push("Madhav");
	cout<<"top element is "<<s.top();
	s.pop();
	cout<<"\ntop element after pop is "<<s.top();
	return 0;
}