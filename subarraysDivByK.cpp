// 974. Subarray Sums Divisible by K
// Leetcode : Medium 09-06-2024

// Math + Prefix Sum 
// Modulo is the King 

int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int count=0;
        mp[0]++;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int remainder=sum % k;
            if(remainder<0)
            {
                remainder+=k;
            }
            if(mp.find(remainder)!=mp.end())
            {
                 count+=mp[remainder];
            }
            mp[remainder]++;
        }
        return count;

    }
