// 2285. Maximum Total Importance of Roads
// Leetcode : Medium 28-06-2024

typedef long long ll;
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<ll> degree(n,0);
        for(int i=0;i<roads.size();i++)
        {
            int u=roads[i][0];
            int v=roads[i][1];
            degree[u]++;
            degree[v]++;
        }
        long long sum=0;
        priority_queue<pair<ll,int>,vector<pair<ll,int>>> pq;
        for(int i=0;i<n;i++)
        {
            pq.push({degree[i],i});
        }
        while(!pq.empty())
        {
            ll x=pq.top().first * n;
            n--;
            pq.pop();
            sum+=x;
        }
        return sum;
    }
