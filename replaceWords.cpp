// 648. Replace Words
// Leetcode: Medium 07-06-2024

string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> s;
        string ans="";
        for(string it:dictionary)
        {
            s.insert(it);
        }
        int i=0;
        while(i<sentence.length())
        {
            int j=i;
            bool flag=0;
            while(j<sentence.length() && sentence[j]!=' ')
            {
                string temp=sentence.substr(i,j-i+1);
                if(s.find(temp)!=s.end() && !flag)
                {
                    flag=true;  
                    if(ans.size()!=0)
                    {
                        ans+=" ";
                    }
                    ans+=temp;                
                }
                j++;
            }
            if(!flag)
            {
                if(ans.size()!=0)
                { 
                    ans+=" ";
                }
                ans+=sentence.substr(i,j-i);
            }
            i=j+1;            
        }
        return ans;
    }
