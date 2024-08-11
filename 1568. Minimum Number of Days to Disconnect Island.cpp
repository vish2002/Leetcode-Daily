// 1568. Minimum Number of Days to Disconnect Island
// LeetCode : Hard 11-08-2024

class Solution {
public:
void DFS(int i,int j,vector<vector<int>>& grid,vector<vector<bool>> &visited,int &m,int &n)
{
    if(i<0 || i>=m || j<0 || j>=n || visited[i][j] || grid[i][j]==0)
    return;

    visited[i][j]=1;
    DFS(i+1,j,grid,visited,m,n);
    DFS(i,j+1,grid,visited,m,n);
    DFS(i-1,j,grid,visited,m,n);
    DFS(i,j-1,grid,visited,m,n);
}
int minIsland(vector<vector<int>>& grid,int &m,int &n)
{
    int island=0;
    vector<vector<bool>> visited(m,vector<bool>(n,0));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]==1  && !visited[i][j])
            {
                DFS(i,j,grid,visited,m,n);
                island+=1;
            }
        }
    }
    return island;
}
    int minDays(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int island=minIsland(grid,m,n);
        if(island>1 || island==0)return 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    grid[i][j]=0;
                    island=minIsland(grid,m,n);
                    grid[i][j]=1;
                    if(island > 1 || island==0)return 1;
                }
            }
        }
        return 2;
    }

};
