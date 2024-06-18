// 826. Most Profit Assigning Work
// Leetcode : Medium 18-06-2024

// Approach 1 : using Priority Queue & sorting 
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
        priority_queue<int> pq;
        bool flag=false;
        for(int i=0;i<m;i++)
        {
            while(j<n && worker[i]>=v[j].first)
            {
                flag=true;
                pq.push(v[j].second);
                j++;
            }
            if(!flag) ans+=0;
            else ans+=pq.top();
        }     
        return ans;   
    }
