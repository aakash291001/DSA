#include<bits/stdc++.h>
using namespace std;
// will return whether there is path or not
bool hasPath(int **edges,int st,int en,int n,bool *visited)
{
	queue<int> q;
	q.push(st);
	visited[st] = true;
	while(q.empty()==0)
	{
		int current = q.front();
		q.pop();
		for(int i=0;i<n;i++)
		{
			if(visited[i]==false&&edges[current][i]==1)
			{
				visited[i] = true;
				q.push(i);
				if(i==en)
				return true;
			}
			if(visited[i]==false&&edges[i][current]==1)
			{
				visited[i] = true;
				q.push(i);
				if(i==en)
				return true;
			}
		}
	}
	return false;
}
bool hasPath(int **edges,int st,int en,int n)
{
	bool *visited = new bool[n];
	for(int i=0;i<n;i++)
	visited[i]= false;
	return hasPath(edges,st,en,n,visited);
}
int main()
{
	int n,e;
	cout<<"Enter no. of vertices and no. of edges\n";
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
	cout<<"Enter starting vertix\n";
	int sv;
	cin>>sv;
	int st,en;
	cout<<"enter starting and ending vertices\n";
	cin>>st>>en;
	cout<<hasPath(edges,st,en,n);
	return 0;
}