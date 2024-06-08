// 523. Continuous Subarray Sum
// Leetcode : Medium 08-06-2024

// Prefix Sum + Basic Maths

// intution 
// for eg : 23 % 6 = 5
// so (23 + 6 ) % 6 =5
// so we put all the remainders with their indexes in the map and if we find any 
// repeating and also the size becomes greater than or equal to 2 we return true else we return false.

bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        mp[0]=-1;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int remainder=sum % k;
            if(mp.find(remainder)!=mp.end())
            {
                int idx=i-mp[remainder];
                if(idx>=2)return true;
            }
            else mp[remainder]=i;
        }
        return false;
    }
