#include<bits/stdc++.h>
using namespace std;
class graph
{
	vector<vector<int>> edge;
	int v;
	public:
		graph(int v)
		{
			this->v = v;
		}
		void addEdge(int f,int s,int w)
		{
			edge.push_back({f,s,w});
		}
//		vector<vector<int>> djkastra(int s)
//		{
//			vector<vector<int>> out;
//			int *source = new int[v];
//			int *parent = new int[v];
//			int *distance = new int[v];
//			bool *visited = new bool[v];
//			for(int i=0;i<v;i++)
//			{
//				source[i] = i;
//				parent[i] = -1;
//				distance[i] = INT_MAX;
//				visited[i]= false;
//			}
//			distance[s]=0;
//			vector<int> vis;
//			vis.push_back(s);
//			visited[s] = true;
//			int count=0;
//			while(vis.size()<v)
//			{
//				int current = vis.back();
//				priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
//				for(auto it:edge)
//				{
//					if(it[0]==current&&visited[it[1]]==false)
//					{
//						int index = it[1];
//						if(parent[index]==-1&&count==0)
//						{
//							distance[index]=it[2];
//								parent[index] = it[0];
//							pq.push(make_pair(distance[index],index));	
//						}
//						else
//						{
//							if(it[2]+distance[current]<distance[index])
//							{
//								distance[index]=it[2]+distance[current];
//								parent[index] = it[0];
//							}
//							pq.push(make_pair(distance[index],index));
//						}
//					}
//					if(it[1]==current&&visited[it[0]]==false)
//					{
//						int index = it[0];
//						if(parent[index]==-1&&count==0)
//						{
//							distance[index]=it[2];
//								parent[index] = it[1];
//							pq.push(make_pair(distance[index],index));	
//						}
//						else
//						{
//							if(it[2]+distance[current]<distance[index])
//							{
//								distance[index]=it[2]+distance[current];
//								parent[index] = it[1];
//							}
//							pq.push(make_pair(distance[index],index));
//						}
//					}
//				}
//			vis.push_back(pq.top().second);
//			visited[pq.top().second]=true;
//			count++;
//			}
//			for(int i=0;i<v;i++)
//			{
//				if(parent[i]!=-1)
//				{
//					out.push_back({source[i],parent[i],distance[i]});
//				}
//			}
//			return out;
//		}
		int findMinVertex(int *distance,bool *visited,int v)
		{
			int minvertex = -1;
			for(int i=0;i<v;i++)
			{
				if(!visited[i]&&(minvertex==-1||distance[i]<distance[minvertex]))
				minvertex=i;
			}
			return minvertex;
		}
	    vector <int> dijkstra(int s)
	    {
	        bool *visited = new bool[v];
			int *distance = new int[v];
			for(int i=0;i<v;i++)
			{
				distance[i] = INT_MAX;
				visited[i] = false;
			}
			distance[s] = 0;
			for(int i=0;i<v;i++)
			{
				int minVertex = findMinVertex(distance,visited,v);
				visited[minVertex]=true;
				for(auto it:edge)
				{
				    if(visited[it[1]]==false&&it[0]==minVertex)
				    {
				        int dist = distance[minVertex]+it[2];
				        if(dist<distance[it[1]])
				        {
				            distance[it[1]] = dist;
				        }
				    }
				    if(visited[it[0]]==false&&it[1]==minVertex)
				    {
				        int dist = distance[minVertex]+it[2];
				        if(dist<distance[it[0]])
				        {
				            distance[it[0]] = dist;
				        }
				    }
				}
			}
			vector<int> out;
			for(int i=0;i<v;i++)
			{
			    out.push_back(distance[i]);
			}
			return out;
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
	vector<int> v = g.dijkstra(0);
	for(int i=0;i<5;i++)
	{
		cout<<v[i];
		cout<<"\n";
	}
	return 0;
}