// 1122. Relative Sort Array
// Leetcode : Easy 11-06-2024

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        map<int,int> mp;
        for(int it: arr1)
        {
            mp[it]++;
        }
        for(int i=0;i<arr2.size();i++)
        {
            if(mp.find(arr2[i])!=mp.end())
            {
                while(mp[arr2[i]]!=0)
                {
                    ans.push_back(arr2[i]);
                    mp[arr2[i]]--;
                }
                if(mp[arr2[i]]==0)
                {
                    mp.erase(arr2[i]);
                }
            }
        }
    for(auto it=mp.begin();it!=mp.end();++it)
    {
        while(it->second!=0)
        {
            ans.push_back(it->first);
            it->second--;
        }
    }
    return ans;
    }
