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
			edge[s].push_back(make_pair(f,w));
		}
		void prims()
		{
			int *weight = new int[v];
			int *parent = new int[v];
			int *visited = new int[v];
			for(int i=0;i<v;i++)
			{
				weight[i] = INT_MAX;
				parent[i] = -1;
				visited[i] = false;
			}
			priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
			parent[0] = -1;
			weight[0] = 0;
			pq.push(make_pair(0,0));
			int count = 0;
			while(pq.empty()==0)
			{
				int current = pq.top().second;
				pq.pop();
				visited[current]=true;
				for(auto it:edge[current])
				{
					if(visited[it.first]==false)
					{
						if(weight[it.first]>it.second)
						{
							weight[it.first]=it.second;
							parent[it.first]= current;
						}
						pq.push(make_pair(weight[it.first],it.first));
					}
				}
			}
			for(int i=0;i<v;i++)
			{
				if(parent[i]!=-1)
				cout<<i<<" "<<parent[i]<<" "<<weight[i]<<"\n";
			}
		}
};
int main()
{
	graph g(5);
	g.addEdge(0,1,4);
	g.addEdge(0,2,8);
	g.addEdge(1,2,2);
	g.addEdge(1,3,6);
	g.addEdge(2,3,3);
	g.addEdge(2,4,9);
	g.addEdge(3,4,5);
	g.prims();
	return 0;
}