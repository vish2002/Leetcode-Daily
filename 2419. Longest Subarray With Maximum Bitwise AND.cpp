// 2419. Longest Subarray With Maximum Bitwise AND
// Leetcode : Medium 14-09-2024

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
         int result = 0, length = 0, maxi = 0;
        for (int ele : nums) {
            maxi = max(maxi, ele);
        }

        for (int ele : nums) {
            if (ele == maxi) {
                result = max(result, ++length);
            } else length = 0;
        }
        return result;
    }
};
