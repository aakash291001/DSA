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
		
		vector<vector<int>> prism()
		{
			
			vector<int> vis,unvis;
			vector<vector<int>> out;
			int *vertex = new int[v];
			int *parent = new int[v];
			int *weight = new int[v];
			bool *visited = new bool[v];
			for(int i=0;i<v;i++)
			{
				vertex[i] = i;
				parent[i] = -1;
				weight[i] = INT_MAX;
				visited[i] = false;
			}
			weight[0] = 0;
			vis.push_back(0);
			visited[0]=true;
			while(vis.size()<v)
			{
				int current = vis.back();
				priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
				for(auto it:edge)
				{
					if(it[0]==current&&visited[it[1]]==false)
					{
						int index=it[1];
						if(it[2]<weight[index])
						{
							weight[index]=it[2];
							parent[index]=it[0];
							pq.push(make_pair(weight[index],index));
						}
					}
					if(it[1]==0&&visited[it[0]]==false)
					{
						int index=it[0];
						if(it[2]<weight[index])
						{
							weight[index]=it[2];
							parent[index]=it[1];
							pq.push(make_pair(weight[index],index));
						}
					}
				}
				vis.push_back(pq.top().second);
				visited[pq.top().second]=true;
			}
			for(int i=0;i<v;i++)
		{
			if(parent[i]!=-1)
			{
				out.push_back({vertex[i],parent[i],weight[i]});
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
	g.addEdge(1,3,6);
	g.addEdge(2,3,3);
	g.addEdge(2,4,9);
	g.addEdge(3,4,5);
	vector<vector<int>> v = g.prism();
	for(int i=0;i<5-1;i++)
	{
		cout<<v[i][0]<<" "<<v[i][1]<<"weight"<<v[i][2];
		cout<<"\n";
	}
	return 0;
}