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
// Using Binary Search
int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();

        vector<pair<int, int>> vec;
        for(int i = 0; i < n; i++) {
            vec.push_back({difficulty[i], profit[i]});
        }

        sort(begin(vec), end(vec));

        //Pre-processing to find the maximum profit till index i at constant time
        for(int i = 1; i < vec.size(); i++) {
            vec[i].second = max(vec[i].second, vec[i-1].second);
        }


        int totalProfit = 0;
        for(int i = 0; i < m; i++) {

            int workerDiffLevel = worker[i];

            //apply b.search on vec
            int l = 0, r = vec.size()-1;
            int maxProfit = 0;
            while(l <= r) {
                int mid = l + (r-l)/2;
                if(vec[mid].first <= workerDiffLevel) {
                    maxProfit = max(maxProfit, vec[mid].second);
                    l = mid+1;
                } else {
                    r = mid-1;
                }
            }

            totalProfit += maxProfit;

        }

        return totalProfit;
    }
