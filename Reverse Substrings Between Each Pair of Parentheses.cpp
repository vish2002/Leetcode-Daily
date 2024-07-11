// 1190. Reverse Substrings Between Each Pair of Parentheses
// LeetCode : Medium 11-07-2024

string reverseParentheses(string s) {
        stack<int> st;
        string result="";
        for(char ch:s)
        {
            if(ch=='(')
            {
                st.push(result.size());
            }
            else if(ch==')' && !st.empty())
            {
                reverse(begin(result)+st.top(),end(result));
                st.pop();
            }else{
                result.push_back(ch);
            }
        }
        return result;
    }
