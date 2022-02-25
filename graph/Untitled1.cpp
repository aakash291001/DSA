#include<bits/stdc++.h>
using namespace std;
void getpathDFS(int **edges,int n,int st,int en,vector<int> &path,bool *visited,int sv)
{
	visited[sv] = true;
	if(sv == en)
	{
		path.push_back(sv);
		return;
	}
	int l=path.size();
	for(int i=0;i<n;i++)
	{
		if(edges[i][sv]==1&&visited[i]==false)
		{
			getpathDFS(edges,n,st,en,path,visited,i);
			if(path.size()==0)
			{
				if(edges[sv][i]==1&&visited[i]==false)
				{
				getpathDFS(edges,n,st,en,path,visited,i);
				if(path.size()!=0)
				path.push_back(i);	
				}
			}
			else
			path.push_back(i);
		}
	}
}
void getPath(int **edges,int n,int st,int en,vector<int> &path,int sv)
{
	bool *visited = new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i] = false;
	}
	getpathDFS(edges,n,st,en,path,visited,sv);
}

int main()
{
	int n,e;
	cout<<"Enter no. of vertices and edges\n";
	cin>>n>>e;
	int **edges = new int*[n];
	for(int i=0;i<n;i++)
	{
		edges[i] = new int[n];
		for(int j=0;j<n;j++)
		edges[i][j] = 0;
	}
	cout<<"Enter edges\n";
	for(int i=0;i<e;i++)
	{
		int f,s;
		cin>>f>>s;
		edges[s][f]=1;
		edges[f][s]=1;
	}
	cout<<"Enter starting and end vertix\n";
	int st,en;
	cin>>st>>en;
	vector<int> path;
	getPath(edges,n,st,en,path,st);
	if(path.size()==0)
	cout<<"No path";
	else
	{
		for(int it:path)
		cout<<it;
	}
	return 0;
}