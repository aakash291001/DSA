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
	graph g(8);
	g.addEdge(1-1,2-1);
	g.addEdge(2-1,3-1);
	g.addEdge(2-1,8-1);
	g.addEdge(3-1,4-1);
	g.addEdge(8-1,5-1);
//	g.addEdge(7-1,5-1);
	g.addEdge(4-1,5-1);
	g.addEdge(5-1,6-1);
	g.addEdge(6-1,7-1);
	cout<<g.bipartiteDFS();
	return 0;
}