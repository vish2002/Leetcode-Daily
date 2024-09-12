// 1684. Count the Number of Consistent Strings
// Leetcode : Easy 12-09-2024

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int mask=0;
        for(int i=0;i<allowed.length();i++){
            int shift=allowed[i]-'a';
            mask|=(1<<shift);
        }
        int ans=0;
        for(auto str:words){
            int i;
            for(i=0;i<str.length();i++){
                if(!((mask>>(str[i]-'a'))&1))
                break;
            }
            if(i==str.length())ans++;
        }
        return ans;
    }
};
