// 884. Uncommon Words from Two Sentences
// Leetcode : Easy 17-09-2024

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp1, mp2;
        vector<string> ans;
        
        // Helper function to populate word count map
        auto populateMap = [](const string& str, unordered_map<string, int>& mp) {
            int j = 0;
            for (int i = 0; i < str.length(); i++) {
                if (str[i] == ' ') {
                    mp[str.substr(j, i - j)]++;
                    j = i + 1;
                } else if (i == str.length() - 1) {
                    mp[str.substr(j, i - j + 1)]++;
                }
            }
        };
        
        // Populate maps for s1 and s2
        populateMap(s1, mp1);
        populateMap(s2, mp2);

        // Find uncommon words in s1
        for (const auto& [word, count] : mp1) {
            if (count == 1 && !mp2.count(word)) {
                ans.push_back(word);
            }
        }

        // Find uncommon words in s2
        for (const auto& [word, count] : mp2) {
            if (count == 1 && !mp1.count(word)) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};
