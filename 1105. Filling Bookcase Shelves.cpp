// 1105. Filling Bookcase Shelves
// LeetCode : Medium 31-07-2024

int Width;
int dp[1001][1001];
    int solve(int i,int rwidth,vector<vector<int>>& books,int maxheight)
    {
        if(i>=books.size())
        {
            return maxheight;
        }
        if(dp[i][rwidth]!=-1)return dp[i][rwidth];

        int width=books[i][0];
        int height=books[i][1];
        int take=INT_MAX,ntake=INT_MAX;

        if(width<=rwidth)
        take=solve(i+1,rwidth-width,books,max(height,maxheight));
        
        if(i!=0)
        ntake=maxheight+solve(i+1,Width-width,books,height);

        return dp[i][rwidth]=min(take,ntake);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(dp,-1,sizeof(dp));
        Width=shelfWidth;
        return solve(0,shelfWidth,books,0);
    }
