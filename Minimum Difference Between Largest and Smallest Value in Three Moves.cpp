// 1509. Minimum Difference Between Largest and Smallest Value in Three Moves
// LeetCode : Medium 03-07-2024

int minDifference(vector<int>& nums) {
        int numsSize = nums.size();
        if (numsSize <= 4) return 0;

        sort(nums.begin(), nums.end());

        int minDiff = INT_MAX;

        for (int left = 0, right = numsSize - 4; left < 4; left++, right++) {
            minDiff = min(minDiff, nums[right] - nums[left]);
        }

        return minDiff;
    }
