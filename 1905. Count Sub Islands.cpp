// 1905. Count Sub Islands
// Leetcode : Medium 28-08-2024

class Solution {
public:
vector<int> row_dir = {1, -1, 0, 0};
vector<int> col_dir = {0, 0, 1, -1};

void DFS(int row, int col, vector<vector<int>>& grid, int m, int n) {
    grid[row][col] = 2;  
    for (int k = 0; k < 4; k++) {
        int newrow = row + row_dir[k];
        int newcol = col + col_dir[k];
        if (newrow >= 0 && newrow < m && newcol >= 0 && newcol < n && grid[newrow][newcol] == 1) {
            DFS(newrow, newcol, grid, m, n);
        }
    }
}

bool DFS2(int row, int col, vector<vector<int>>& grid2, vector<vector<int>>& grid1, int m, int n) {
    if (row < 0 || row >= m || col < 0 || col >= n || grid2[row][col] != 1) {
        return true;
    }
    
    if (grid1[row][col] != 2) {
        return false;
    }

    grid2[row][col] = 2; 
    bool isSubIsland = true;

    for (int k = 0; k < 4; k++) {
        int newrow = row + row_dir[k];
        int newcol = col + col_dir[k];
        isSubIsland = DFS2(newrow, newcol, grid2, grid1, m, n) && isSubIsland;
    }

    return isSubIsland;
}

int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int m = grid1.size();
    int n = grid1[0].size();
    int ans = 0;

    // Mark all islands in grid1
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid1[i][j] == 1) {
                DFS(i, j, grid1, m, n);
            }
        }
    }

    // Count sub-islands in grid2
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid2[i][j] == 1) {
                if (DFS2(i, j, grid2, grid1, m, n)) {
                    ans++;
                }
            }
        }
    }

    return ans;
}

};
