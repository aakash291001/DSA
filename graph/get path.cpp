#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[],int f,int s)
{
    adj[f].push_back(s);
    adj[s].push_back(f);
}
void printShortestDistance(vector<int> adj[],int st,int dt,int n,unordered_map<int,pair<int,int>> &umap)
{
    bool *visited = new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
        if(i==st)
        {
            umap[i].first=0;
        }
        else{
            umap[i].first=INT_MAX;
        }
    }
    queue<int> q;
    q.push(st);
    visited[st]=true;
    umap[st].second=-1;
    while(q.empty()==0)
    {
        int current = q.front();
        q.pop();
        for(auto it:adj[current])
        {
            if(visited[it]==false)
            {
                visited[it]=true;
                q.push(it);
                umap[it].first=umap[current].first+1;
                umap[it].second=current;
            }
        }
    }
}
vector<int> getPath(unordered_map<int,pair<int,int>> umap,vector<int> adj[],int n,int st,int en)
{
    vector<int> v;
    v.push_back(en);
        int dist=umap[en].first;
        int ad=umap[en].second;
        while(dist!=0)
        {
            v.push_back(ad);
            ad=umap[ad].second;
            dist--;
        }
    return v;
}
int main()
{
    cout<<"Enter vertices\n";
    int n;
    cin>>n;
    vector<int> adj[n];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 2);
    addEdge(adj, 3, 4);
    addEdge(adj, 3, 7);
    addEdge(adj, 4, 5);
    addEdge(adj, 4, 6);
    addEdge(adj, 4, 7);
    addEdge(adj, 5, 6);
    addEdge(adj, 6, 7);
    unordered_map<int,pair<int,int>> umap;
    printShortestDistance(adj,0,7,n,umap);
    for(int i=0;i<n;i++)
    {
        cout<<i<<" "<<umap[i].first<<" "<<umap[i].second;
        cout<<"\n";
    }
    vector<int> v=getPath(umap,adj,n,0,7);
    for(auto it:v)
    {
        cout<<it<<" ";
    }
    return 0;
}