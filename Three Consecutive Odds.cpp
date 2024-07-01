// 1550. Three Consecutive Odds
// LeetCode : Easy 01-07-2024

bool threeConsecutiveOdds(vector<int>& arr) {
        int count=0;
        for(int i=0;i<arr.size();i++)
        {
            if((arr[i] & 1)==1)
            {
                count++;
                if(count==3)return true;
            }
            else count=0;
            
        }
        return false;
    }
