// 1653. Minimum Deletions to Make String Balanced
// LeetCode : Medium 30-07-2024

// Approach 1:Using Stack
int minimumDeletions(string s) {
        int n=s.length();
        int count=0;
        stack<char> st;

        for(int i=0;i<n;i++)
        {
            if(!st.empty() && s[i]=='a' && st.top()=='b')
            {
                st.pop();
                count++;
            }else st.push(s[i]);
        }
        return count;
    }

// Approach 2:Precomputing left_b count and right_a count
int minimumDeletions(string s) {
        int n=s.length();
        vector<int> left_b(n,0);
        vector<int> right_a(n,0);
        int countb=0;
        for(int i=0;i<n;i++)
        {
            left_b[i]=countb;
            if(s[i]=='b')countb++;
        }
        int counta=0;
        for(int i=n-1;i>=0;i--)
        {
            right_a[i]=counta;
            if(s[i]=='a')counta++;
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            mini=min(mini,left_b[i]+right_a[i]);
        }
        return mini;
    }
// Without Extra Space
int minimumDeletions(string s) {
        int n=s.length();
        int countb=0;
        int counta=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='a')counta++;
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a')counta--;
            mini=min(mini,counta+countb);
            if(s[i]=='b')countb++;

        }
        return mini;
    }
