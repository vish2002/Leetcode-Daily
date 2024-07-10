// 1598. Crawler Log Folder
// LeetCode : Easy 10-07-2024

int minOperations(vector<string>& logs) {
        stack<string> st;
        for(auto &it: logs)
        {
            if(it=="../" && !st.empty())
            {
                st.pop();
            }
            else if(it!="./" && it!="../")
            {
                st.push(it);
            }
        }
        return st.size();
    }
