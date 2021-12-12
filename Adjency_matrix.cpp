#include<bits/stdc++.h>
using namespace std;
// this is part of a feature1 branch
void print(int **edges,int e,int sv,bool *visited){
    cout<<sv;
    visited[sv]=true;
    for(int i=0;i<e;i++)
    {
        if(edges[sv][i]==1){
            if(visited[i]==true)
            continue;
            print(edges,e,i,visited);
        }
        if(edges[i][sv]==1){
            if(visited[i]==true)
            continue;
            print(edges,e,i,visited);
        }
    }
}
int main()
{
    int n;//no. of vertices
    int e;//no. of edges
    cout<<"Enter no. of vertices and no. of edges respectively\n";
    cin>>n>>e;
    int **edges = new int*[n];//matrix which store edges 
    for(int i=0;i<n;i++)
    {
        edges[i] = new int[n]; 
        for(int j=0;j<n;j++)
        edges[i][j] = 0;
    }
    for(int i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f]  = 1;
    }
    bool *visited = new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    print(edges,n,0,visited);
    return 0;
}