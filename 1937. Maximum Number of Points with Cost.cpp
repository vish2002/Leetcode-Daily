// 1937. Maximum Number of Points with Cost
// LeetCode : Medium 17-08-2024

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int rows = points.size();
        int col = points[0].size();

        vector<long long> prev(col);
        for (int j = 0; j < col; j++) {
            prev[j] = points[0][j];
        }

        for (int i = 1; i < rows; i++) {
            vector<long long> left(col);
            vector<long long> right(col);

            vector<long long> curr(col);
            left[0] = prev[0];
            right[col - 1] = prev[col - 1];

            for (int j = 1; j < col; j++) {
                left[j] = max(prev[j], left[j - 1] - 1);
            }
            for (int j = col - 2; j >= 0; j--) {
                right[j] = max(prev[j], right[j + 1] - 1);
            }

            for (int j = 0; j < col; j++) {
                curr[j] = points[i][j] + max(left[j], right[j]);
            }
            prev = curr;
        }
        return *max_element(begin(prev), end(prev));
    }
};
