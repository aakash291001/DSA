#include<bits/stdc++.h>
using namespace std;
//print DFS fun 2
void printDFS(int **edges,int sv,int e,bool *visited)
{
	cout<<sv<<" ";
	visited[sv] = true;
	for(int i=0;i<e;i++)
	{
		if(edges[i][sv]==1&&visited[i]==false)
		printDFS(edges,i,e,visited);
		if(edges[sv][i]==1&&visited[i]==false)
		printDFS(edges,i,e,visited);
	}
}
void printDFS(int **edges,int sv,int n,int e)
{
	bool *visited = new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i] = false;
	}
	printDFS(edges,sv,n,visited);
	for(int i=0;i<n;i++)
	{
		if(visited[i]==false)
		printDFS(edges,i,n,visited);
	}
	
}
void printBFS(int **edges,int sv,int n)
{
	queue<int> q;
	bool *visited = new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i] = false;
	}
	q.push(sv);
	visited[sv] = true;
	while(q.empty()==0)
	{
		int current = q.front();
		cout<<current<<" ";
		q.pop();
		for(int i=0;i<n;i++)
		{
			if(visited[i]==false&&edges[current][i]==1)
			{
				visited[i] = true;
				q.push(i);
			}
			if(visited[i]==false&&edges[i][current]==1)
			{
				visited[i] = true;
				q.push(i);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(visited[i]==false)
		{
			q.push(i);
	visited[i] = true;
	while(q.empty()==0)
	{
		int current = q.front();
		cout<<current<<" ";
		q.pop();
		for(int i=0;i<n;i++)
		{
			if(visited[i]==false&&edges[current][i]==1)
			{
				visited[i] = true;
				q.push(i);
			}
			if(visited[i]==false&&edges[i][current]==1)
			{
				visited[i] = true;
				q.push(i);
			}
		}
	}
		}
	}
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
		for(int j = 0;j<n;j++)
		edges[i][j] = 0;
	}
	cout<<"Enter edges\n";
	for(int i=0;i<e;i++)
	{
		int f,s;
		cin>>f>>s;
		edges[s][f] = 1;
		edges[f][s] = 1;
	}
	cout<<"Enter starting vertix\n";
	int sv;
	cin>>sv;
	cout<<"DFS\n";
	printDFS(edges,sv,n,e);
	cout<<"BFS\n";
	printBFS(edges,sv,n);
	return 0;
}