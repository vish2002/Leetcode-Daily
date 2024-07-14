// 726. Number of Atoms
// LeetCode : Hard 14-07-2024

string countOfAtoms(string formula) {
        int n=formula.length();
        stack<unordered_map<string,int>> st;
        st.push(unordered_map<string,int>());
        int i=0;
        while(i<n)
        {
            if(formula[i]=='(')
            {
                st.push(unordered_map<string,int>());
                i++;
            }
            else if(formula[i]==')')
            {
                unordered_map<string,int> temp=st.top();
                st.pop();
                string multiplier="";
                i++;
                while(i<n && isdigit(formula[i]))
                {
                    multiplier+=formula[i];
                    i++;
                }
                if(!multiplier.empty())
                {
                    int mult=stoi(multiplier);
                    for(auto &it: temp)
                    {
                        temp[it.first]=it.second*mult;
                    }
                }
                for(auto &it: temp)
                {
                    st.top()[it.first]+=it.second;
                }
            }
            else
            {
                string current="";
                current+=formula[i];
                i++;
                while(i<n && islower(formula[i]))
                {
                    current+=formula[i];
                    i++;
                }
                string currentnum="";
                while(i<n && isdigit(formula[i]))
                {
                    currentnum+=formula[i];
                    i++;
                }
                int count=currentnum.empty()?1:stoi(currentnum);
                st.top()[current]+=count;
            }
        }
        map<string,int> sortedmap(st.top().begin(),st.top().end());
        string result;
        for(auto &it:sortedmap)
        {
            result+=it.first;
            if(sortedmap[it.first] >1)
            {
                result+=to_string(it.second);
            }
        }
        return result;
    }
