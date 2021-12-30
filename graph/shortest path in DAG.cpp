#include<bits/stdc++.h>
using namespace std;
class graph
{
	int v;
	list<pair<int,int>> *edge;
	public:
		graph(int v)
		{
			this->v = v;
			edge = new list<pair<int,int>>[v];
		}
		void addEdge(int f,int s,int w)
		{
			edge[f].push_back(make_pair(s,w));
		}
		void dfs(int i,stack<int> &st,bool *visited)
		{
			visited[i]=true;
			for(auto it:edge[i])
			{
				if(visited[it.first]==false)
				{
					dfs(it.first,st,visited);
				}
			}
			st.push(i);
		}
		void dfs(int sr,int en)
		{
			bool *visited;
			visited = new bool[v];
			for(int i=0;i<v;i++)
			{
				visited[v]=false;
			}
			stack<int> st;
			dfs(sr,st,visited);
			int *dist;
			dist = new int[v];
			for(int i=0;i<v;i++)
			{
				dist[i] = INT_MAX;
			}
			dist[sr]=0;
			while(st.empty()==0)
			{
				int curr = st.top();
				st.pop();
				for(auto it:edge[curr])
				{
					if(dist[it.first]>dist[curr]+it.second)
					dist[it.first]=dist[curr]+it.second;
				}
			}
			cout<<dist[en];
		}
};
int main()
{
	graph g(6);
	g.addEdge(0,1,2);
	g.addEdge(0,4,1);
	g.addEdge(1,2,3);
	g.addEdge(4,2,2);
	g.addEdge(2,3,6);
	g.addEdge(4,5,4);
	g.addEdge(5,3,1);
	g.dfs(0,3);
	return 0;
}