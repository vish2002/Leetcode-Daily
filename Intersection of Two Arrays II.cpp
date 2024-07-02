// 350. Intersection of Two Arrays II
// LeetCode : Easy 02-07-2024

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(begin(nums1),end(nums1));
        sort(begin(nums2),end(nums2));
        vector<int> ans;
        int i=0;
        int j=0;
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i]==nums2[j])
            {
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i]<nums2[j])
            {
                i++;
            }
            else if(nums1[i]>nums2[j])
            {
                j++;
            }
        }
        return ans;
    }
