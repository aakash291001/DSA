#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;
class graph
{
	map<int ,list<int >> l;
	int v;
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
	void bfs(int  src)
	{
		map<int ,bool> visited;
		queue<int > q;
		q.push(src);
		visited[src] = true;
		while(q.empty()==0)
		{
			int  current = q.front();
			cout<<current<<" ";
			q.pop();
			for(auto nbr:l[current])
			{
				if(visited[nbr]==false)
				{
					q.push(nbr);
					visited[nbr]=true;
				}
			}
		}
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
	g.bfs(0);
	return 0;
}