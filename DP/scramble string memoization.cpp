#include<bits/stdc++.h>
using namespace std;
unordered_map<string,bool> umap;
int solve(string str1,string str2)
{
	if(str1==str2)
	return true;
	int n = str1.length()-1;
	string temp = str1;
	temp.push_back('_');
	temp.append(str2);
	if(umap.find(temp)!=umap.end())
	return umap[temp];
	else
	{
		umap[temp]=false;
	for(int k=1;k<=n;k++)
	{
		int l = n-k+1;
		
		//swap
		int temp1,temp2,temp3,temp4;
		string s1,s2,s3,s4;
		s1 = str1.substr(0,k);
		s2 = str2.substr(l,k);
		s3 = str1.substr(k,l);
		s4 = str2.substr(0,l);
		//swap first
		string sw1 = s1;
		sw1.push_back('_');
		sw1.append(s2);
		if(umap.find(sw1)!=umap.end())
		temp1 = umap[sw1];
		else
		temp1 = umap[sw1] = solve(s1,s2);
		//swap second
		string sw2 = s3;
		sw2.push_back('_');
		sw2.append(s4);
		if(umap.find(sw2)!=umap.end())
		temp2 = umap[sw2];
		else
		temp2 = umap[sw2] = solve(s3,s4);
		int sw = temp2&&temp1;
		
		//noswap
		//noswap first
		string s5,s6,s7,s8;
		s5 = str1.substr(0,k);
		s6 = str2.substr(0,k);
		s7 = str1.substr(k,l);
		s8 = str2.substr(k,l);
		string nsw1 = s5;
		nsw1.push_back('_');
		nsw1.append(s6);
		if(umap.find(nsw1)!=umap.end())
		temp3 = umap[nsw1];
		else
		temp3 = umap[nsw1] = solve(s5,s6);
		//swap second
		string nsw2 = s7;
		nsw2.push_back('_');
		nsw2.append(s8);
		if(umap.find(nsw2)!=umap.end())
		temp4 = umap[nsw2];
		else
		temp4 = umap[nsw2] = solve(s7,s8);
		int nsw = temp3&&temp4;
		if(nsw||sw)
		{
		umap[temp] = true;
		break;
		}
	}	
	return umap[temp];
	}
}
int main()
{
	string str1,str2;
	str1="great";
	str2="rkeat";
	cout<<solve(str1,str2);
	return 0;
}