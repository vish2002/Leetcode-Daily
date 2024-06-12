// 75. Sort Colors
// Leetcode: Medium 12-06-2024

// using counting sort 
 void sortColors(vector<int>& nums) {
        vector<int> ans;
        map<int,int> mp ;
        for(auto it: nums)
        {
            mp[it]++;
        }
        vector<int> temp={0,1,2};
        for(int i=0;i<temp.size();i++)
        {
            if(mp.find(temp[i])!=mp.end())
            {
                while(mp[temp[i]]!=0)
                {
                    ans.push_back(temp[i]);
                    mp[temp[i]]--;
                }
                if(mp[temp[i]]==0)
                mp.erase(temp[i]);
            }
        }
    nums=ans;
    }

// O(n) solution 
    void sortColors(vector<int>& nums) {
        int l=0;
        int m=0;
        int h=nums.size()-1;
        while(m<=h)
        {
            if(nums[m]==0 )
            {
                swap(nums[l],nums[m]);
                l++;
                m++;
            }
            else if(nums[m]==1)
            m++;
            else if(nums[m]==2)
            {
                swap(nums[m],nums[h]);
                h--;
            }
        }
    }
