// 2418. Sort the People
// LeetCode : Easy 22-07-2024

// Method 1 using vector<pair>
vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> temp ;
        vector<string> ans;
        for(int i=0;i<names.size();i++)
        {
            temp.push_back({heights[i],names[i]});
        }
        sort(begin(temp),end(temp),greater<pair<int,string>>());
        for(int i=0;i<temp.size();i++)
        {
            ans.push_back(temp[i].second);
        }
        return ans;
    }
// Method 2 using map (chances are there it might fail for some values as map does not store duplicate keys)
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string> temp;
        vector<string> ans;
        for(int i=0;i<names.size();i++)
        {
            temp[heights[i]]=names[i];
        }
        for(auto it=temp.rbegin();it!=temp.rend();it++)
        {
            ans.push_back(it->second);
        }
        return ans;
    }

// Method 3 using multimap

vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    multimap<int, string> temp;
    vector<string> ans;
    
    for (int i = 0; i < names.size(); i++) {
        temp.insert({heights[i], names[i]});
    }
    
    for (auto it = temp.rbegin(); it != temp.rend(); it++) {
        ans.push_back(it->second);
    }
    
    return ans;
}
