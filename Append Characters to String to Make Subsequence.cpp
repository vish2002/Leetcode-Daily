// Append Characters to String to Make Subsequence
// LeetCode: Medium 03-06-2024
 int appendCharacters(string s, string t) {
        int n=s.length();
        int m=t.length();
        int i=0;
        int j=0;
        int ans=0;
        while(i<n && j<m)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        ans=m-j;
        return ans;
    }
