// 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
// LeetCode : Medium 23-06-2024

int longestSubarray(vector<int>& nums, int limit) {
    int n = nums.size();
    set<int> s;
    int i = 0;
    int j = 0;
    int validmaxi = 0;
    while (j < n) {
        s.insert(nums[j]);
        int diff = *s.rbegin() - *s.begin();
        if (diff > limit) {
            s.erase(nums[i]); 
            i++;
            j=i;
        } else {
            validmaxi = max(validmaxi, j - i+1);
            j++; 
        }
    }
    return validmaxi;
}
