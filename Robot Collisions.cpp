// 2751. Robot Collisions
// Leetcode : Hard 13-07-20024


vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pair<int,int>> pos;
        vector<int> ans;
        vector<int> temp;
        for(int i=0;i<positions.size();i++)
        {
            pos.push_back({positions[i],i});
        }
        sort(begin(pos),end(pos));
        stack<int> st;
        for(int i=0;i<pos.size();i++)
        {
            while(!st.empty() && directions[st.top()]=='R' && directions[pos[i].second]== 'L')
            {
                if(healths[st.top()]<healths[pos[i].second])
                {
                    st.pop();  
                    healths[pos[i].second]--;              
                }
                else if(healths[st.top()]>healths[pos[i].second])
                {
                    healths[st.top()]--;
                    pos[i].second=-1;
                    break;
                }
                else if(healths[st.top()]==healths[pos[i].second])
                {
                    st.pop();
                    pos[i].second=-1;
                    break;
                }
            }
            if(pos[i].second!=-1)
            st.push(pos[i].second);
        }
        while(!st.empty())
        {
            temp.push_back(st.top());
            st.pop();
        }
        sort(begin(temp),end(temp));
        for(int i=0;i<temp.size();i++)
        {
            ans.push_back(healths[temp[i]]);
        }
        return ans;
    }
