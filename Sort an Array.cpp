// 912. Sort an Array
// LeetCode : Medium 25-07-2024

vector<int> sortArray(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int mini=*min_element(begin(nums),end(nums));
        int maxi=*max_element(begin(nums),end(nums));
        int j=0;
        for(int i=mini;i<=maxi;i++)
        {
            while(mp[i]!=0)
            {
                 nums[j]=i;
                 mp[i]--;
                 j++;
            }
        }
        return nums;
    }
