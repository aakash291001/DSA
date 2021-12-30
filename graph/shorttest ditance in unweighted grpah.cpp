#include<bits/stdc++.h>
using namespace std;
class graph
{
	int v;
	list<int> *edge;
	public:
		graph(int v)
		{
			this->v = v;
			edge = new list<int>[v];
		}
		void addEdge(int f,int s)
		{
			edge[s].push_back(f);	
			edge[f].push_back(s);
		}	
		void sp(int src,int en)
		{
			int *visited;
			visited=new int[v];
			for(int i=0;i<v;i++)
			{
				visited[i]=INT_MAX;
			}
			queue<int> q;
			q.push(src);
			visited[src]=0;
			while(q.empty()==0)
			{
				int current = q.front();
				q.pop();
				for(auto it:edge[current])
				{
					if(visited[it]==INT_MAX){
						q.push(it);
						visited[it]=visited[current]+1;
					}
				}
			}
			cout<<visited[en];
		}
};
int main()
{
	graph g(9);
	g.addEdge(0,1);
	g.addEdge(0,3);
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(2,6);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(5,6);
	g.addEdge(6,7);
	g.addEdge(6,8);
	g.addEdge(7,8);
	g.sp(0,6);
	return 0;
}