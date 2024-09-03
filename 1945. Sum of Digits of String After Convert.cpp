// 1945. Sum of Digits of String After Convert
// Leetcode: Easy 03-09-2024

class Solution {
public:
    int getLucky(string s, int k) {
        string sum="";
        for(int i=0;i<s.length();i++){
            sum+=to_string(s[i]-'a'+1);
        }
        int ans=0;
        while(k){
            ans=0;
            for(int i=0;i<sum.length();i++){
                ans+=(sum[i]-'0');
            }
            sum=to_string(ans);
            k--;
        }
        return ans;
    }
};
