// 1460. Make Two Arrays Equal by Reversing Subarrays
// LeetCode : Easy 03-08-2024

bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto it:target)
        {
            mp[it]++;
        }
        for(auto it:arr)
        {
            if(mp.count(it))
            {
                mp[it]--;
                if(mp[it]==0)mp.erase(it);
            }
            else return 0;
        }
        return 1;
    }
