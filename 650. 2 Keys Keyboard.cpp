// 650. 2 Keys Keyboard
// Leetcode : Medium 19-08-2024

// Recurssion + Memoization 
class Solution {
public:
    int n;
    vector<vector<int>> memo;

    int minSteps(int n) {
        if (n == 1) return 0;
        this->n = n;

        memo = vector<vector<int>>(n + 1, vector<int>(n / 2 + 1, 0));
        return 1 + minStepsHelper(1, 1);
    }

    int minStepsHelper(int currLen, int pasteLen) {
        if (currLen == n) return 0;
        if (currLen > n) return 1000;

        if (memo[currLen][pasteLen] != 0) return memo[currLen][pasteLen];

        int opt1 = 1 + minStepsHelper(currLen + pasteLen, pasteLen);
        int opt2 = 2 + minStepsHelper(currLen * 2, currLen);
        memo[currLen][pasteLen] = min(opt1, opt2);
        return memo[currLen][pasteLen];
    }
};

// Gredy + DP

class Solution {
public:
    int minSteps(int n) {
        if(n==1)return 0;
        vector<int> dp(n+1,0);
        dp[2]=2;
        for(int i=3;i<=n;i++)
        {
            int fact=i/2;
            while(fact>=1)
            {
                if(i%fact == 0)
                {
                    int steps=dp[fact];
                    int copy=1;
                    int paste=(i/fact)-1;
                    dp[i]=steps+copy+paste;
                    break;
                }
                else fact--;
            }
        }
        return dp[n];
    }
};
