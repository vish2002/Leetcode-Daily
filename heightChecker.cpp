// 1051. Height Checker
// Leetcode: Easy 10-06-2024

// Using Sorting 
int heightChecker(vector<int>& heights) {
        int count=0;
        vector<int> temp=heights;
        sort(temp.begin(),temp.end());
        for(int i=0;i<heights.size();i++)
        {
            if(heights[i]!=temp[i])
            {
                count++;
            }
        }
        return count;
    }
