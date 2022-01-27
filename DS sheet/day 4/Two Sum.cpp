//#include<bits/stdc++.h>
//using namespace std;
//vector<int> twosum(int A[],int sum,int n)
//{
//	vector<int> p;
//	for(int i=0;i<n-1;i++)
//	{
//		int curr = A[i];
//		for(int j=i+1;j<n;j++)
//		{
//			if(A[i]+A[j]==sum)
//			{
//				p.push_back(A[i]);
//				p.push_back(A[j]);
//				break;
//			}
//		}
//	}
//	return p;
//}
//vector<int> twosum2(int A[],int sum,int n)
//{
//	vector<int> p;
//	unordered_map<int,int> ump;
//	for(int i=0;i<n;i++)
//	{
//	    ump[A[i]]=1;
//	}
//	for(int i=0;i<n;i++)
//	{
//	    ump[A[i]]=0;
//	    if(ump[sum-A[i]]==1)
//	    {
//	        p.push_back(A[i]);
//	        p.push_back(sum-A[i]);
//	        break;
//	    }
//	}
//	return p;
//}
//int main()
//{
//	int A[] = {2,7,11,15};
//	vector<int> p;
//	p = twosum2(A,9,4);
//	cout<<p[0]<<" "<<p[1];
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
vector<int> twosum(int A[],int sum,int n)
{
	vector<int> p;
	for(int i=0;i<n-1;i++)
	{
		int curr = A[i];
		for(int j=i+1;j<n;j++)
		{
			if(A[i]+A[j]==sum)
			{
				p.push_back(A[i]);
				p.push_back(A[j]);
				break;
			}
		}
	}
	return p;
}
vector<int> twosum2(int A[],int sum,int n)
{
	vector<int> p;
	unordered_map<int,int> ump;
	for(int i=0;i<n;i++)
	{
	    ump[A[i]]=1;
	}
	for(int i=0;i<n;i++)
	{
	    ump[A[i]]=0;
	    if(ump[sum-A[i]]==1)
	    {
	        p.push_back(A[i]);
	        p.push_back(sum-A[i]);
	        break;
	    }
	}
	return p;
}

vector<pair<int,int>> twosum3(int A[],int sum,int n)
{
	vector<pair<int,int>> p;
	int l = 0;
	int r = n-1;
	while(l<=r)
	{
	    if(A[l]+A[r]==sum)
	    {
	        p.push_back(make_pair(A[l],A[r]));
	        l++;
	        r--;
	    }
	    else if(A[l]+A[r]<sum)
	    {
	        l++;
	    }
	    else
	    {
	        r--;
	    }
	}
	return p;
}
int main()
{
	int A[] = {2,7,11,15};
	vector<pair<int,int>> p;
	p = twosum3(A,9,4);
	int n = p.size();
	for(int i=0;i<n;i++)
	{
	    cout<<p[i].first<<" "<<p[i].second<<"\n";
	}
	return 0;
}