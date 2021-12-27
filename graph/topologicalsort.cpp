#include<bits/stdc++.h>
using namespace std;
class graph
{
	int v;
	list<int> *edge;
	public:
		graph(int v)
		{
			this->v=v;
			edge = new list<int>[v];
		}
		void addEdge(int f,int s)
		{
			edge[f].push_back(s);
		}
		void dfs(int sv,bool *visited,stack<int> &st)
		{
			visited[sv]=true;
			for(auto it:edge[sv])
			{
				if(visited[it]==false)
				{
					dfs(it,visited,st);
					st.push(it);
				}
			}
		}
		void toposort()
		{
			stack<int> st;
			bool *visited;
			visited = new bool[v];
			for(int i=0;i<v;i++)
			{
				visited[i]=false;
			}
			for(int i=0;i<v;i++)
			{
				if(visited[i]==false)
				{
					dfs(i,visited,st);
					st.push(i);	
				}
			}
			vector<int> ans;
			while(st.empty()==0)
			{
				ans.push_back(st.top());
				st.pop();
			}
			for(auto it:ans)
			cout<<it;
		}
};
int main()
{
	graph g(6);
	g.addEdge(4,0);
	g.addEdge(4,1);
	g.addEdge(3,1);
	g.addEdge(2,3);
	g.addEdge(5,2);
	g.addEdge(5,0);
	g.toposort();
	return 0;
}