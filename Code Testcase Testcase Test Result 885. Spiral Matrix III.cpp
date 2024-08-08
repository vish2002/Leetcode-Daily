// 885. Spiral Matrix III
// Leetcode : Medium 08-08-2024

class Solution {
public:
bool isValid(int r,int c,int rows,int cols)
{
    if(r<0 || r>=rows || c<0 || c>=cols)
    {
        return false;
    }
    return true;
}
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        int size=rows*cols;
        int steps=1;
        while(ans.size()<size)
        {
            for(int i=0;i<steps;i++)
            {
                if(isValid(rStart,cStart,rows,cols))
                {
                    ans.push_back({rStart,cStart});
                }
                cStart++;
            }
            for(int i=0;i<steps;i++)
            {
                if(isValid(rStart,cStart,rows,cols))
                {
                    ans.push_back({rStart,cStart});
                }
                rStart++;
            }
            steps++;
            for(int i=0;i<steps;i++)
            {
                if(isValid(rStart,cStart,rows,cols))
                {
                    ans.push_back({rStart,cStart});
                }
                cStart--;
            }
            for(int i=0;i<steps;i++)
            {
                if(isValid(rStart,cStart,rows,cols))
                {
                    ans.push_back({rStart,cStart});
                }
                rStart--;
            }
            steps++;
        }
        return ans;
    }
};
