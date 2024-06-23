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
// Efficient approach using sliding window 

int longestSubarray(vector<int>& nums, int limit) {
    priority_queue<pair<int, int>, vector<pair<int, int>>> maxheap;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
    int validmaxi = 0;
    int i = 0;
    int j = 0;
    int n = nums.size();
    while (j < n) {
        maxheap.push({nums[j], j});
        minheap.push({nums[j], j});
        while(maxheap.top().first - minheap.top().first>limit)
        {
            i=min(maxheap.top().second ,minheap.top().second)+1;
            while(maxheap.top().second<i)
            maxheap.pop();
            while(minheap.top().second<i)
            minheap.pop();
        }      
        validmaxi = max(validmaxi, j - i + 1);
        j++;
    }
    return validmaxi;
}
