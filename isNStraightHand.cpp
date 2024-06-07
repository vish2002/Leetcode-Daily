// 846. Hand of Straights
// LeetCode: Medium 07-06-2024

bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0)
        {
            return false;
        }
        map<int,int> mp;
        for(int i=0;i<hand.size();i++)
        {
            mp[hand[i]]++;
        }
        while(!mp.empty())
        {
            int card=mp.begin()->first;
            for(int i=0;i<groupSize;i++)
            {
                if(mp.find(card+i)==mp.end())
                {
                    return false;
                }
                else mp[card+i]--;
                if(mp[card+i]==0)
                mp.erase(card+i);
            }
        }
        return true;
    }
