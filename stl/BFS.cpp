#include<bits/stdc++.h>
using namespace std;
void printBFS(int **edges,int n,int sv,bool *visited)
{
	queue<int> pending;
	pending.push(sv);
	visited[sv]=true;
	while(pending.empty()!=0)
	{
		int current = pending.pop();
		cout<<current<<" ";
		for(int i=0;i<n;i++)
		if(edges[current][i]==1&&visited[i]!=true)
		{
			pending.push(i);
			visited[i] = true;
		}
	}
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
	for(int i=0;i<e;i++)
	{
		int f,s;
		cin>>f>>s;
		edges[f][s] = edges[s][f] = 1;
	}
	bool *visit = new bool[n];
	cout<<"enter first vertice\n";
	int sv;
	cin>>sv;
	queue<int> q;
	q.push(sv);
	for(int i=0;i<n;i++)
	visit[i]=false;
	visit[sv]=true;
	printBFS(edges,n,visit,q);
	return 0;
}