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
		vector<vector<int>> djkastra(int s)
		{
			vector<vector<int>> out;
			int *source = new int[v];
			int *parent = new int[v];
			int *distance = new int[v];
			bool *visited = new bool[v];
			for(int i=0;i<v;i++)
			{
				source[i] = i;
				parent[i] = -1;
				distance[i] = INT_MAX;
				visited[i]= false;
			}
			distance[s]=0;
			vector<int> vis;
			vis.push_back(s);
			visited[s] = true;
			int count=0;
			while(vis.size()<v)
			{
				int current = vis.back();
				priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
				for(auto it:edge)
				{
					if(it[0]==current&&visited[it[1]]==false)
					{
						int index = it[1];
						if(parent[index]==-1&&count==0)
						{
							distance[index]=it[2];
								parent[index] = it[0];
							pq.push(make_pair(distance[index],index));	
						}
						else
						{
							if(it[2]+distance[current]<distance[index])
							{
								distance[index]=it[2]+distance[current];
								parent[index] = it[0];
							}
							pq.push(make_pair(distance[index],index));
						}
					}
					if(it[1]==current&&visited[it[0]]==false)
					{
						int index = it[0];
						if(parent[index]==-1&&count==0)
						{
							distance[index]=it[2];
								parent[index] = it[1];
							pq.push(make_pair(distance[index],index));	
						}
						else
						{
							if(it[2]+distance[current]<distance[index])
							{
								distance[index]=it[2]+distance[current];
								parent[index] = it[1];
							}
							pq.push(make_pair(distance[index],index));
						}
					}
				}
				vis.push_back(pq.top().second);
				visited[pq.top().second]=true;
				
			count++;
			}
			for(int i=0;i<v;i++)
			{
				if(parent[i]!=-1)
				{
					out.push_back({source[i],parent[i],distance[i]});
				}
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
	vector<vector<int>> v = g.djkastra(0);
	for(int i=0;i<5-1;i++)
	{
		cout<<v[i][0]<<" "<<v[i][1]<<" "<<"weight"<<" "<<v[i][2];
		cout<<"\n";
	}
	return 0;
}