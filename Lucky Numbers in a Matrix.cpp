// 1380. Lucky Numbers in a Matrix
// LeetCode : Easy 19-07-2024

class Solution {
public:


vector<int> luckyNumbers (vector<vector<int>>& matrix) {
    vector<int> minrow;
    vector<int> maxcol(matrix[0].size(), INT_MIN);
    vector<int> ans;

    // Find the minimum value in each row
    for(int i = 0; i < matrix.size(); i++) {
        int mini = INT_MAX;
        for(int j = 0; j < matrix[0].size(); j++) {
            mini = min(mini, matrix[i][j]);
        }
        minrow.push_back(mini);
    }

    // Find the maximum value in each column
    for(int j = 0; j < matrix[0].size(); j++) {
        for(int i = 0; i < matrix.size(); i++) {
            maxcol[j] = max(maxcol[j], matrix[i][j]);
        }
    }

    // Check for lucky numbers
    for(int i = 0; i < minrow.size(); i++) {
        for(int j = 0; j < maxcol.size(); j++) {
            if(minrow[i] == maxcol[j]) {
                ans.push_back(minrow[i]);
            }
        }
    }

    return ans;
}

};
