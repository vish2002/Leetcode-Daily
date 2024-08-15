// 719. Find K-th Smallest Pair Distance
// LeetCode : Hard 14-08-2024

class Solution {
public:
     int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        int maxEl = *max_element(begin(nums), end(nums));
        vector<int> vec(maxEl + 1, 0);

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int d = abs(nums[i] - nums[j]);
                vec[d]++;
            }
        }


        for (int d = 0; d <= maxEl; d++) {
            k -= vec[d];
            if (k <= 0) {
                return d; 
            }
        }
        return -1;
    }

};

// Binary Search + Sliding Window
class Solution {
public:
    int slidingWindowCount(vector<int>& nums, int D) {
        int count = 0;
        int n = nums.size();
        int i = 0;
        int j = 1;

        while (j < n) {
            while (nums[j] - nums[i] > D) {
                ++i;
            }
            count += j - i;
            j++;
        }
        return count;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        int l = 0;
        int r = nums[n - 1] - nums[0];
        int result = 0;

        while (l <= r) {
            int mid = (l + r) / 2;
            int count = slidingWindowCount(nums, mid);

            if (count < k) {
                l = mid + 1;
            } else {
                result = mid; // Store the mid as a potential result
                r = mid - 1;
            }
        }
        return result;
    }
};
