// 912. Sort an Array
// LeetCode : Medium 25-07-2024


vector<int> sortArray(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int mini=*min_element(begin(nums),end(nums));
        int maxi=*max_element(begin(nums),end(nums));
        int j=0;
        for(int i=mini;i<=maxi;i++)
        {
            while(mp[i]!=0)
            {
                 nums[j]=i;
                 mp[i]--;
                 j++;
            }
        }
        return nums;
    }

// Merge Sort 

void merge(vector<int> &nums, int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int L[n1], R[n2];
    int k = l;

    for (int i = 0; i < n1; i++) {
        L[i] = nums[k++];
    }
    for (int j = 0; j < n2; j++) {  // Change i to j here
        R[j] = nums[k++];
    }

    int i = 0, j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <R[j]) {
            nums[k] = L[i];
            i++;
        } else {
            nums[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        nums[k++] = L[i++];
    }
    while (j < n2) {
        nums[k++] = R[j++];
    }
}

void mergesort(vector<int> &nums, int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;

    mergesort(nums, l, mid);
    mergesort(nums, mid + 1, r);

    merge(nums, l, mid, r);
}

vector<int> sortArray(vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;
    mergesort(nums, l, r);
    return nums;
}

