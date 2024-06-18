// 826. Most Profit Assigning Work
// Leetcode : Medium 18-06-2024

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=difficulty.size();
        int m=worker.size();
        vector<pair<int,int>> v;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            v.push_back({difficulty[i],profit[i]});
        }
        sort(begin(v),end(v));
        sort(begin(worker),end(worker));
        int j=0;
        int maxi=0;
        for(int i=0;i<m;i++)
        {
            while(j<n && worker[i]>=v[j].first)
            {
                maxi=max(v[j].second,maxi);
                j++;
            }
            ans+=maxi;
        }     
        return ans;   
    }
