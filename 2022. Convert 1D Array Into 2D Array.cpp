// 2022. Convert 1D Array Into 2D Array
// Leetcode : Easy 01-09-2024

vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans(m);
        int size=original.size();
        if(size != m*n)return {};

        int row=0;
        int i=0;
        while(row<m){
            int x=i+n;
            for(i;i<x;i++){
                ans[row].push_back(original[i]);
            }
            row++;
        }
        return ans;
    }
