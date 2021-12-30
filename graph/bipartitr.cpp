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
			edge[f].push_back(s);
			edge[s].push_back(f);
		}
		bool bipartite()
		{
			int *col;
			col = new int[v];;
			for(int i=0;i<v;i++)
			{
				col[i] = -1;
			}
			queue<int> q;
			q.push(0);
			col[0] = 1;
			while(q.empty()==0)
			{
				int current = q.front();
				q.pop();
				for(auto it:edge[current])
				{
					if(it!=current)
					{
					if(col[it]==-1)
					{
						col[it] = 1-col[current];
						q.push(it);
					}
					else if(col[it]==col[current])
					{
						return false;
					}
				}
			}
			} 
			return true;
		}
		bool bipartiteDFS(int i,int par,int *col)
		{
			if(par==-1)
			col[i]=1;
			else
			{
				if(col[par]==1)
				col[i]=0;
				else
				col[i]=1;
			}
			for(auto it:edge[i])
			{
				if(col[i]==-1)
				{
					bool ans = bipartiteDFS(it,i,col);
					if(ans==false)
					return false;	
				}
				else
				{
					if(col[i]==col[it])
					return false;
				}
			}
			return true;
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
					if(visited[it]>visited[current]+1){
						q.push(it);
						visited[it]=visited[current]+1;
					}
				}
			}
			cout<<visited[en];
		}
		bool bipartiteDFS()
		{
			int *col;
			col = new int[v];
			for(int i=0;i<v;i++)
			{
				col[i] = -1;
			}
			return bipartiteDFS(0,-1,col);
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
//	cout<<g.bi.
	return 0;
}