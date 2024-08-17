// 1937. Maximum Number of Points with Cost
// LeetCode : Medium 17-08-2024

// DP Approach + Prefix and Suffix Array Approach 
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

// Recursion + Memoization( Gave TLE at 143 test case )

class Solution {
public:
    long long solve(int i,int j,vector<vector<int>>& points,vector<vector<long long>> &dp)
    {
        if(i>=points.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        long long maxi=0;
        for(int col=0;col<points[0].size();col++)
        {
            long long score=0;
            score+=points[i][col];
            if(i>0)
            {
                score-=abs(j-col);
            }
            maxi=max(maxi,score+solve(i+1,col,points,dp));
        }
        return dp[i][j]=maxi;
    }
    long long maxPoints(vector<vector<int>>& points) {
        int m=points.size();
        int n=points[0].size();
        vector<vector<long long >> dp(m+1,vector<long long>(n+1,-1));
        return solve(0,0,points,dp);
    }
};
