#include<bits/stdc++.h>
using namespace std;
class graph
{
	vector<vector<int>> edge;
	int v;
	public:
		graph(int v)
		{
			this->v=v;
		}
		void addEdge(int w,int f,int s)
		{
			edge.push_back({w,f,s});
		}
		int findParent(int current,int *parent)
		{
			if(current==parent[current])
			return current;
			else
			{
				return findParent(parent[current],parent);
			}
		}
		vector<vector<int>> mst(int n)
		{
			vector<vector<int>> out;
			sort(edge.begin(),edge.end());
			int *parent = new int[v];
			for(int i=0;i<v;i++)
			{
				parent[i]=i;
			}
			int count=0;
			int i=0;
			while(count!=v-1)
			{
				int source = edge[i][1];
				int dest = edge[i][2];
				int sp = findParent(source,parent);
				int dp = findParent(dest,parent);
				if(dp!=sp)
				{
					out.push_back(edge[i]);
//					for(int j=0;j<v;j++)
//					{
//						if(parent[j]==parent[source])
//						{
//							parent[j]=parent[dest];
//						}
//					}
					parent[sp]=dp;
					count++;
				}
				i++;
			}
			return out;
		}
};
int main()
{
	graph g(6);
	g.addEdge(1,0,1);
	g.addEdge(5,0,2);
	g.addEdge(10,2,3);
	g.addEdge(4,0,3);
	g.addEdge(3,1,3);
	g.addEdge(6,1,2);
	g.addEdge(7,3,4);
	g.addEdge(8,2,4);
	g.addEdge(2,4,5);
	g.addEdge(9,2,5);
	g.addEdge(6,3,5);
	vector<vector<int>> v = g.mst(6);
	for(int i=0;i<6-1;i++)
	{
		cout<<v[i][1]<<" "<<v[i][2];
		cout<<"\n";
	}
	return 0;
}