// Maximum Score From Removing Substrings
// LeetCode : Medium 12-07-2024

class Solution {
public:
    string removemaxi(string &s,string &maxi)
    {
        stack<char> st;
        string temp="";
        for(char ch:s)
        {
            if(ch==maxi[1] && !st.empty() && st.top() == maxi[0])
            {
                st.pop();
            }else st.push(ch);
        }
        while(!st.empty())
        {
            temp.push_back(st.top());
            st.pop();
        }
        reverse(begin(temp),end(temp));
        return temp;
    }
    int maximumGain(string s, int x, int y) {
        string maxi="";
        int score=0;
        string mini="";
        if(x>y)
        {
            maxi="ab";
        }else{maxi="ba";}
        if(x<y)
        {
            mini="ab";
        }else {mini="ba";}
        
        string temp=removemaxi(s,maxi);
        int z=s.length()-temp.length();
        score+=(z/2)*max(x,y);
        string temp2=removemaxi(temp,mini);
        int k=temp.length()-temp2.length();
        score+=(k/2)*min(x,y);
        return score;
    }
};
