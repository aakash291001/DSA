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
		}
		int* norder()
		{
			int *nor;
			nor = new int[v];
			for(int i=0;i<v;i++)
			{
				nor[i]=0;
			}
			for(int i=0;i<v;i++)
			{
				for(auto it:edge[i])
				nor[it]++;
			}
			return nor;
		}
		void topoSort()
		{
			queue<int> q;
			int *nor;
			nor = new int[v];
			for(int i=0;i<v;i++)
			{
				nor[i]=0;
			}
			for(int i=0;i<v;i++)
			{
				for(auto it:edge[i])
				nor[it]++;
			}
			for(int i=0;i<v;i++)
			{
				if(nor[i]==0)
				q.push(i);
			}
			vector<int> ans;
			while(q.empty()==0)
			{
				int current = q.front();
				ans.push_back(current);
				q.pop();
				for(auto it:edge[current])
				{
					nor[it]--;
					if(nor[it]==0)
					q.push(it);
				}
			}
			for(int i=0;i<ans.size();i++)
			{
				cout<<ans[i];
			}
		}
};
int main()
{
	graph g(6);
	g.addEdge(0,2);
	g.addEdge(0,3);
	g.addEdge(1,2);
	g.addEdge(1,5);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.topoSort();
	return 0;
}