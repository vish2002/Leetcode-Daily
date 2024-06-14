// 945. Minimum Increment to Make Array Unique
// LeetCode: Medium 14-06-2024

// using Sorting 
int minIncrementForUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int ans = 0;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] <= nums[i - 1]) {
            int increment = nums[i - 1] + 1 - nums[i];
            nums[i] += increment;
            ans += increment;
        }
    }

    return ans;
}
