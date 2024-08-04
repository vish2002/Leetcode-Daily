// 1508. Range Sum of Sorted Subarray Sums
// LeetCode : Medium 04-08-2024

// Using Set
int rangeSum(vector<int>& nums, int n, int left, int right) {
        int mod=1e9+7;
        multiset<int> subarraysum;
        for(int i=0;i<nums.size();i++)
        {
            int sum=0;
            for(int j=i;j<nums.size();j++)
            {
                sum=(sum % mod+nums[j])%mod;
                subarraysum.insert(sum);
            }
        }
        auto it=subarraysum.begin();
        advance(it,left-1);
        int sum=0;
        for(int i=left;i<=right;i++)
        {
            sum=((sum %mod)+(*it% mod))%mod;
            it++;
        }
        return sum;
  }

// Using Vector 
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int mod=1e9+7;
        vector<int> subarraysum;
        for(int i=0;i<nums.size();i++)
        {
            int sum=0;
            for(int j=i;j<nums.size();j++)
            {
                sum=(sum % mod+nums[j])%mod;
                subarraysum.push_back(sum);
            }
        }
        sort(begin(subarraysum),end(subarraysum));
        int sum=0;
        for(int i=left-1;i<=right-1;i++)
        {
            sum=((sum %mod)+(subarraysum[i] % mod))%mod;
        }
        return sum;
    }
};

