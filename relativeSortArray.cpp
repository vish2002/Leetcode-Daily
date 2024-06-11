// 1122. Relative Sort Array
// Leetcode : Easy 11-06-2024


// Using Counting Sort 
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

// using Sorting + Lambda 

    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp;
        for(int i=0;i<arr2.size();i++)
        {
            mp[arr2[i]]=i;
        }
        for(auto it: arr1)
        {
            if(mp.find(it)==mp.end())
            {
                mp[it]=1e9;
            }
        }
        auto lambda=[&](int& num1,int& num2)
        {
            if(mp[num1]== mp[num2])
            {
                return num1<num2;
            }
            return mp[num1]<mp[num2];
        };
        sort(begin(arr1),end(arr1),lambda);
        return arr1;
    }
