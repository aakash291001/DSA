#include<bits/stdc++.h>
using namespace std;
class graph
{
    list<int> *edge;
    int v;
    public:
    graph(int v)
    {
        this->v = v;
        edge = new list<int>[v];
    }
    void addEdge(int f,int s)
    {
        edge[f].push_back(s);
        edge[s].push_back(f);
    }
    void discovery(int *disc,bool *visited,int &count,int p,int sv,int *low,int &bri)
    {
        visited[sv] = true;
        count++;
        disc[sv] = count;
        low[sv] = disc[sv];
        for(auto it:edge[sv])
        {
            if(it!=p)
            {
                if(visited[it]==false)
                {
                    discovery(disc,visited,count,sv,it,low,bri);
                    low[sv] = min(low[sv],low[it]);
                }
                else
                {
                    low[sv] = min(low[sv],disc[it]);
                }   
            }
        }
        if(low[sv]>disc[p]&&disc[sv]!=1)
        bri++;
    }
    void printDFS()
    {
        bool *visited = new bool[v];
        int *disc = new int[v];
        int *par = new int[v];
        int *low = new int[v];
        for(int i=0;i<v;i++)
        {
            visited[i] = false;
            disc[i] = 0;
        }
        int count=0;
        int bri=0;
        discovery(disc,visited,count,0,0,low,bri);
        for(int i=0;i<v;i++)
        {
            cout<<i<<"="<<disc[i]<<" "<<low[i]<<"\n";
        }
        cout<<"bridge="<<bri; 
    }
};
int main()
{
    graph g(8);
    g.addEdge(0,7);
    g.addEdge(7,4);
    g.addEdge(4,1);
    g.addEdge(1,0);
    g.addEdge(1,3);
    g.addEdge(3,2);
    g.addEdge(2,5);
    g.addEdge(5,6);
    g.addEdge(6,2);
    g.printDFS();
    return 0;
}