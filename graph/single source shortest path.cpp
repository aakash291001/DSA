#include<bits/stdc++.h>
using namespace std;
class graph
{
	int v;
	map<int,list<int>> l;
	public:
	graph(int v)
	{
		this->v = v;
	}
	void addEdge(int x,int y)
	{
		l[x].push_back(y);
		l[y].push_back(x);
	}
	void bfs(int src)
	{
		map<int,bool> visited;
		queue<int> q;
		q.push(src);
		visited[src] = true;
		while(q.empty()==0)
		{
			int current = q.front();
			q.pop();
			cout<<current;
			for(auto nbr:l[current])
			{
				if(visited[nbr]==false)
				{
					q.push(nbr);
					visited[nbr] = true;
				}
			}
		}
	}
	void sssp(int src,int en)
	{
		map<int,int> dist;
		queue<int> q;
		q.push(src);
		for(auto it:l)
		{
			int index = it.first;
			dist[index] = INT_MAX;
		}
		dist[src]=0;
		while(q.empty()==0)
		{
			int current = q.front();
			q.pop();
			for(auto nbr:l[current])
			{
				if(dist[nbr]==INT_MAX)
				{
					q.push(nbr);
					dist[nbr]=dist[current]+1;
				}
			}
		}
		cout<<"answer";
		cout<<dist[en];
	}
};
int main()
{
	graph g(5);
	g.addEdge(0,1);
	g.addEdge(0,3);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);
	cout<<"Enter starting and end point\n";
	int st,en;
	cin>>st>>en;
	g.sssp(st,en);
	return 0;
}