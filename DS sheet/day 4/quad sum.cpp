#include<bits/stdc++.h>
using namespace std;
int bSearch(int A[],int l,int h,int ele)
{
	if(l<=h)
	{
		int m = (l+h)/2;
		if(A[m]==ele)
		{
			return m;
		}
		else if(ele<A[m])
		{
			return bSearch(A,l,m-1,ele);
		}
		else 
		{
			return bSearch(A,m+1,h,ele);
		}
	}
	else
	return -1;
}
vector<vector<int>> quadSum(int A[],int sum,int n)
{
	vector<vector<int>> ans;
	sort(A,A+n);
	set<vector<int>> sq;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				int temp = sum-(A[i]+A[j]+A[k]);
				int l = bSearch(A,k+1,n-1,temp);
				if(l!=-1&&(l!=i&&l!=j&&l!=k))
				{
					vector<int> vec;
					vec.push_back(A[i]);
					vec.push_back(A[j]);
					vec.push_back(A[k]);
					vec.push_back(A[l]);
					sort(vec.begin(),vec.end());
					sq.insert(vec);
				}
			}
		}
	}
	for(auto it=sq.begin();it!=sq.end();it++)
	{
		ans.push_back(*it);
	}
	return ans;
}
vector<vector<int>> quadSum2(int A[],int sum,int n)
{
	vector<vector<int>> ans;
	sort(A,A+n);
	set<vector<int>> sq;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int sum2 = sum-A[i]-A[j];
			int l = j+1;
			int r = n-1;
			while(l<=r)
			{
			    
			    if(A[l]+A[r]<sum2)
			    {
			        l++;
			    }
			    else if(A[l]+A[r]>sum2)
			    {
			        r--;
			    }
			    else
			    {
			    	vector<int> temp;
			    	temp.push_back(A[i]);
			    	temp.push_back(A[j]);
			    	temp.push_back(A[l]);
			    	temp.push_back(A[r]);
			    	ans.push_back(temp);
			 		l++;
					r--;
					while(l<r&&A[l]==temp[2]) l++;
			    	while(l<r&&A[r]==temp[3]) r--;
			    }
			}
			while(j<n-1&&A[j]==A[j+1])
			j++;
		}
		while(i<n-1&&A[i]==A[i+1])
			i++;
	}
	return ans;
}
int main()
{
	int A[]= {4,3,3,4,2,1,2,1,1};
	vector<vector<int>> ans;
	ans = quadSum2(A,9,9);
	int n= ans.size();
	for(int i=0;i<n;i++)
	{
		cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<" "<<ans[i][3]<<"\n";
	}
	return 0;
}