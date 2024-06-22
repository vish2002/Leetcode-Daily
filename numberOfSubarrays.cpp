// 1248. Count Number of Nice Subarrays
// Leetcode : Medium 22-06-2024

// Intution: Calculate prefixsum for no.of odd values in nums and simultaneously find for its another pair that gives the sum equals k.
int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n=nums.size();
        int oddcount=0;
        int ans=0;
        mp[0]=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
            {
                oddcount+=0;
            }
            else oddcount+=1;
            if(mp.find(oddcount-k)!=mp.end())
            ans+=mp[oddcount-k];
            mp[oddcount]++;
        }
        return ans;
    }
