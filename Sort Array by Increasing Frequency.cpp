// Sort Array by Increasing Frequency
// LeetCode: Easy 23-07-2024

vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> hash;
        for(int i=0;i<nums.size();i++)
        {
            hash[nums[i]]++;
        }
        auto lambda=[&](int &num1,int &num2)
        {
            if(hash[num1]==hash[num2])
            {
                return num1>num2;
            }
            return hash[num1]<hash[num2];
        };
        sort(begin(nums),end(nums),lambda);
        return nums;
    }
