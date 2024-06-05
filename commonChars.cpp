// 1002. Find Common Characters
// Leetcode: Easy 05-06-2024

    vector<string> commonChars(vector<string>& words) {
        vector<int>minfreq(26,0);
        for(char c:words[0])
        {
            minfreq[c-'a']++;
        }
        vector<string> ans;
        for(int i=1;i<words.size();i++)
        {
            vector<int> hash(26,0);
            for(char c:words[i])
            {
                hash[c-'a']++;
            }
            for(int i=0;i<26;i++)
            {
                minfreq[i]=min(minfreq[i],hash[i]);
            }
        }
        for(int i=0;i<26;i++)
        {
            while(minfreq[i]--)
            {
            ans.push_back(string(1,i+'a'));
            }
        }
        return ans;
    }
