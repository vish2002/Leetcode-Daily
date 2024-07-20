// 1605. Find Valid Matrix Given Row and Column Sums
// LeetCode : Medium 20-07-2024

vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m=rowSum.size();
        int n=colSum.size();
        vector<vector<int>> ans(m,vector<int>(n,0));

        int i=0;
        int j=0;
        while(i<m && j<n)
        {
            int x=min(rowSum[i],colSum[j]);;
            ans[i][j]=x;
            rowSum[i]-=x;
            colSum[j]-=x;
            if(rowSum[i]==0)
            {
                i++;
            }
            else j++;
        }
        return ans;
    }
