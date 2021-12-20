#include<bits/stdc++.h>
using namespace std;
bool solve(string str1,string str2)
{
	if(str1==str2)
	return true;
	int n = str1.length()-1;
	for(int k=1;k<=n;k++)
	{
		int sw=solve(str1.substr(0,k),str2.substr(n-k+1,k))&&solve(str1.substr(k,n-k+1),str2.substr(0,n-k+1));
		int nsw = solve(str1.substr(0,k),str2.substr(0,k))&&solve(str1.substr(k,n-k+1),str2.substr(k,n-k+1));
		if(nsw||sw)
		return true;
	}
	return false;
}
int main()
{
	string str1,str2;
	str1="great";
	str2="rkeat";
	cout<<solve(str1,str2);
	return 0;
}