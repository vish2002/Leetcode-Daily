// 840. Magic Squares In Grid
// LeetCode : Medium 09-08-2024

bool solve(int row, int col, vector<vector<int>>& grid) {
        vector<int> r(3, 0);
        vector<int> c(3, 0);
        vector<int> diag(2, 0);
        vector<int> count(10, 0);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int num = grid[i + row][j + col];
                if (num < 1 || num > 9 || count[num]++)
                    return false;

                r[i] += num;
                c[j] += num;
                if (i == j)
                    diag[0] += num;
                if (j == 2 - i)
                    diag[1] += num;
            }
        }
        for (int k = 0; k < 3; k++) {
            if (r[k] != 15 || c[k] != 15)
                return false;
        }

        if (diag[0] != 15 || diag[1] != 15)
            return false;

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i <= m - 3; i++) {
            for (int j = 0; j <= n - 3; j++) {
                if (solve(i, j, grid))
                    count++;
            }
        }
        return count;
    }
