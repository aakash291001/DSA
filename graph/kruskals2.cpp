#include<bits/stdc++.h>
using namespace std;

class graph
{
	int v;
	vector<vector<int>> edge;
	public:
		graph(int v)
		{
			this->v = v;
		}
		void addEdge(int f,int s,int w)
		{
			edge.push_back({f,s,w});
		}
		void uni(int *parent,int i,int j)
		{
			for(int k=0;k<v;k++)
			{
				if(parent[k]==j)
				parent[k]=i;
			}
		}
		void kruskals()
		{
			sort(edge.begin(),edge.end());
			vector<vector<int>> mst;
			int *parent = new int[v];
			for(int i=0;i<v;i++)
			{
				parent[i] = i;
			}
			int i=0;
			int count=0;
			while(count<v-1)
			{
				int v1 = edge[i][0];
				int v2 = edge[i][1];
				if(parent[v1]!=parent[v2])
				{
					mst.push_back(edge[i]);
					uni(parent,v1,v2);
					count++;
				}
				i++;
			}
			for(int i=0;i<v-1;i++)
			{
				cout<<mst[i][0]<<" "<<mst[i][1]<<" "<<mst[i][2]<<" ";
				cout<<"\n";
			}
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
	g.kruskals();
	return 0;
}