// 2134. Minimum Swaps to Group All 1's Together II
// LeetCode : Medium 02-08-2024

class Solution {
public:
int minSwaps(vector<int>& nums) {
    int ocount = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) ocount++;
    }

    int zerocount = 0;
    for (int i = 0; i < ocount; i++) {
        if (nums[i] == 0) zerocount++;
    }

    int mini = zerocount; 

    int i = ocount;
    int j = 0;
    while (i < nums.size()) {
        int entry = nums[i];
        int exit = nums[j];
        if (exit == 0) zerocount--;
        if (entry == 0) zerocount++;
        mini = min(mini, zerocount);
        j++;
        i++;
    }

    i = 0;
    while (j < nums.size()) {
        int entry = nums[i];
        int exit = nums[j];
        if (exit == 0) zerocount--;
        if (entry == 0) zerocount++;
        mini = min(mini, zerocount);
        j++;
        i++;
    }

    return mini;
}

};
