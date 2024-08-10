// 959. Regions Cut By Slashes
// Leetcode : Medium 10-08-2024

class Solution {
public:

   void DFS(vector<vector<bool>> &matrix,int i,int j)
   {
    if(i<0 || i>=matrix.size() || j<0 || j>=matrix[0].size() || matrix[i][j]==1)
    return;
    
    matrix[i][j]=1;

    DFS(matrix,i+1,j);
    DFS(matrix,i-1,j);
    DFS(matrix,i,j+1);
    DFS(matrix,i,j-1);

   }
    int regionsBySlashes(vector<string>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();

        int regions = 0;
        vector<vector<bool>> matrix((rows*3),vector<bool>(cols*3));
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j]=='/')
                {
                    matrix[i*3][j*3+2]=1;
                    matrix[i*3+1][j*3+1]=1;
                    matrix[i*3+2][j*3]=1;
                }
                else if(grid[i][j]=='\\')
                {
                    matrix[i*3][j*3]=1;
                    matrix[i*3+1][j*3+1]=1;
                    matrix[i*3+2][j*3+2]=1;
                }
            }
        }
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    DFS(matrix,i,j);
                    regions++;
                }
            }
        }
        return regions;
    }

};
