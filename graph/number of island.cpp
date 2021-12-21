#include<bits/stdc++.h>
using namespace std;
void dfs(int i,int j,vector<vector<char>> &grid)
{
//	if(i>=0&&i<grid.size()&&j>=0&&j<grid[0].size()&&grid[i][j]=='1')
//	{
//		grid[i][j]='0';
		if(i+1>=0&&i+1<grid.size()&&j>=0&&j<grid[0].size()&&grid[i+1][j]=='1')
		{
			grid[i+1][j]='0';
			dfs(i+1,j,grid);
		}
		if(i-1>=0&&i-1<grid.size()&&j>=0&&j<grid[0].size()&&grid[i-1][j]=='1')
		{
			grid[i-1][j]='0';
			dfs(i-1,j,grid);
		}
		if(i>=0&&i<grid.size()&&j+1>=0&&j+1<grid[0].size()&&grid[i][j+1]=='1')
		{
			grid[i][j+1]='0';
			dfs(i,j+1,grid);
		}
		if(i>=0&&i<grid.size()&&j-1>=0&&j-1<grid[0].size()&&grid[i][j-1]=='1')
		{
			grid[i][j-1]='0';
			dfs(i,j-1,grid);
		}
		if(i+1>=0&&i+1<grid.size()&&j-1>=0&&j-1<grid[0].size()&&grid[i+1][j-1]=='1')
		{
			grid[i+1][j-1]='0';
			dfs(i+1,j-1,grid);
		}
		if(i-1>=0&&i-1<grid.size()&&j-1>=0&&j-1<grid[0].size()&&grid[i-1][j-1]=='1')
		{
			grid[i-1][j-1]='0';
			dfs(i-1,j-1,grid);
		}
		if(i+1>=0&&i+1<grid.size()&&j+1>=0&&j+1<grid[0].size()&&grid[i+1][j+1]=='1')
		{
			grid[i+1][j+1]='0';
			dfs(i+1,j+1,grid);
		}
		if(i-1>=0&&i-1<grid.size()&&j+1>=0&&j+1<grid[0].size()&&grid[i-1][j+1]=='1')
		{
			grid[i-1][j+1]='0';
			dfs(i-1,j+1,grid);
		}
//	}
	else
	return;
}
int numIslands(vector<vector<char>>& grid) {
    if(grid.empty()==1)
    return 0;
    int cres=0;
    for(int i=0;i<grid.size();i++)
    {
        for(int j=0;j<grid[i].size();j++)
        {
            if(grid[i][j]=='1')
            {
                dfs(i,j,grid);
                grid[i][j]='0';
                cres++;
            }
        }
    }
    return cres;
}
int main()
{
	vector<vector<char>> grid;
	grid = {{'0','1'},{'1','0'},{'1','1'},{'1','0'}};
	cout<<numIslands(grid);
	return 0;
}