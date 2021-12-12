#include<bits/stdc++.h>
using namespace std;
void printDFS(int **edges,int n,int sv)
{
    bool *visited = new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i] = false;
    }
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    while(q.empty()==0)
    {
        int current=q.front();
        q.pop();
        cout<<current;
        for(int i=0;i<n;i++)
        {
            if(edges[i][current]==1&&visited[i]==false)
            {
                visited[i]=true;
                q.push(i);
            }
        }
    }
}
int main()
{
    int n,e;
    cout<<"Enter no. of vertices and edges\n";
    cin>>n>>e;
    int **edges = new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i]= new int[n];
        for(int j=0;j<n;j++)
        {
            edges[i][j] = 0;
        }
    }
    cout<<"Enter edges connection\n";
    for(int i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    cout<<"Enter first vertix\n";
    int sv;
    cin>>sv;
    bool *visited = new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i] = false;
    }
    printDFS(edges,n,sv);
    return 0;
}