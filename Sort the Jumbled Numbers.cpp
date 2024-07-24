//2191. Sort the Jumbled Numbers
// LeetCode : Medium 24-07-2024

vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            int x=nums[i];
            string temp="";
            while(x!=0)
            {
                int rem=x%10;
                string t="";
                t+=to_string(mapping[rem]);
                temp=t+temp;
                x/=10;
            }
            if(temp.size()!=0)
            mp[nums[i]]=stoi(temp);
            else mp[nums[i]]=mapping[nums[i]];
        }

        auto lambda=[&](int &num1,int &num2)
        {
            if(mp[num1]==mp[num2])
            return false;

            if(mp[num1]<mp[num2])return true;

            return false;
        };

        sort(nums.begin(),nums.end(),lambda);
        return nums;
    }
