// 409. Longest Palindrome
// Leetcode: Easy  04-06-2024

int longestPalindrome(string s) {
        vector<int> H(60,0);
        for(int i=0;i<s.length();i++)
        {
            H[(s[i])-'A']++;
        }
        int sum =0;
        bool flag=false;
        for(int i=0;i<H.size();i++)
        {
            int x=H[i];
            if(x%2!=0)
            {
                sum+=x-1;
                flag=true;
            }
            else sum+=x;
        }
        if(flag)
        {
            sum+=1;
        }
        return sum;

    }
