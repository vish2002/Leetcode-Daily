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

// using sliding window

int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int oddCount = 0;
        int count    = 0;
        int result   = 0;

        int i = 0;
        int j = 0;
        //Best example to understand the use of count variable - {2, 1, 2, 1}, output : 6
        while(j < n) {

            if(nums[j] % 2 != 0) { //ODD
                oddCount++;
                count    = 0; //We need to reset this to avoid over counting. Example : [1,1,2,1,1], k = 3
            }

            while(oddCount == k) {
                count++;

                if(i < n && nums[i] % 2 == 1) { //ODD
                    oddCount--;
                }
                i++;
            }

            result += count;
            j++;
        }

        return result;
    }
