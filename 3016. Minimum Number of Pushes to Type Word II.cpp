// 3016. Minimum Number of Pushes to Type Word II
// Leetcode : Medium 06-08-2024

// Without Map 
class Solution {
public:
    int minimumPushes(string word) {
        int count=8;
        int result=0;
        vector<int> ans(26,0);
        for(auto it:word)
        {
            ans[it-'a']++;
        }
        sort(begin(ans),end(ans),greater<int>());
        int i=1;
        for(auto it:ans)
        {
            if(count==0)
            {
                count=8;
                i++;
            }
            int freq=it;
            result+=freq*i;
            count--;
        }
        return result;
    }
};

// With Map
class Solution {
public:
    int minimumPushes(string word) {
        int count=8;
        int result=0;
        unordered_map<int,int> hash;
        for(auto it:word)
        {
            hash[it-'0']++;
        }
        vector<pair<int,int>> ans;
        for(auto it: hash)
        {
            ans.push_back({it.second,it.first});
        }
        sort(ans.begin(),ans.end(),greater<pair<int,int>>());
        int i=1;
        for(auto it:ans)
        {
            if(count==0)
            {
                count=8;
                i++;
            }
            int freq=it.first;
            result+=freq*i;
            count--;
        }
        return result;
    }
};
