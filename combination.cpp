#include<iostream>
using namespace std;
int combi(int n,int r)
{
	int p;
	if(r==0||r==n)
	return 1;
	return combi(n-1,r-1)+combi(n-1,r); 
}
int main()
{
	cout<<combi(4,1);
	return 0;
}
