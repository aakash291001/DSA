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
		void djkastre(int src)
		{
			bool *visited;
			visited = new bool[v];
			int *dist;
			dist= new int[v];
			for(int i=0;i<v;i++)
			{
				visited[i]=false;
				dist[i] = INT_MAX;
			}
			priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
			pq.push(make_pair(0,src));
			dist[src] = 0;
			for(int i=0;i<v;i++)
			{
				pair<int,int> curr = pq.top();
				visited[curr.second]=true;
				pq = priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>();
				for(auto it:edge[curr.second])
				{
					if(visited[it.first]==false)
					{
						if(dist[it.first]>dist[curr.second]+it.second)
						{
							dist[it.first]=dist[curr.second]+it.second;		
						}
						pq.push(make_pair(dist[it.first],it.first));	
					}
				}
				
			}
			for(int i=0;i<v;i++)
			{
				cout<<dist[i]<<" ";
						}			
		}
};
int main()
{
	graph g(5);
	g.addEdge(0,1,4);
	g.addEdge(0,2,8);
	g.addEdge(1,2,2);
	g.addEdge(1,3,5);
	g.addEdge(2,3,5);
	g.addEdge(2,4,9);
	g.addEdge(3,4,4);
	g.djkastre(0);
	return 0;
}