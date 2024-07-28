// 2045. Second Minimum Time to Reach Destination
// LeetCode:Hard 28-07-2024

// Dijkstra
class Solution {
public:
#define P pair<int,int>
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int,vector<int>> adj;
        for(auto &edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> d1(n+1,INT_MAX);
        vector<int> d2(n+1,INT_MAX);
        priority_queue<P,vector<P>,greater<P>> pq;
        pq.push({0,1});
        d1[1]=0;
        while(!pq.empty())
        {
            int Node=pq.top().second;
            int timepassed=pq.top().first;
            pq.pop();

            if(Node  == n && d2[n]!=INT_MAX)
            return d2[n];

            int div = timepassed/change;
            if(div % 2 == 1)
            {
                timepassed = change*(div+1);
            } 
            for(auto &ngbr : adj[Node])
            {
                if(d1[ngbr]>timepassed+time)
                {
                    d2[ngbr]=d1[ngbr];
                    d1[ngbr]=timepassed+time;
                    pq.push({d1[ngbr],ngbr});
                }
                else if(d2[ngbr]>timepassed+time && d1[ngbr]!=timepassed+time)
                {
                    d2[ngbr]=timepassed+time;
                    pq.push({timepassed+time,ngbr});
                }
            }
        }
        return -1;
    }
};
// BFS
#define P pair<int,int>
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int,vector<int>> adj;
        for(auto &edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> d1(n+1,INT_MAX);
        vector<int> d2(n+1,INT_MAX);
        queue<P>q;
        q.push({1,1}); //{Node,Freq}
        d1[1]=0;
        while(!q.empty())
        {
            int freq=q.front().second;
            int Node=q.front().first;
            q.pop();
            int timepassed =(freq == 1)?d1[Node]:d2[Node];
            if(Node  == n && d2[n]!=INT_MAX)
            return d2[n];

            int div = timepassed/change;
            if(div % 2 == 1)
            {
                timepassed = change*(div+1);
            } 
            for(auto &ngbr : adj[Node])
            {
                if(d1[ngbr]==INT_MAX)
                {
                    d1[ngbr]=timepassed+time;
                    q.push({ngbr,1});
                }else if(d2[ngbr]==INT_MAX && d1[ngbr]!=timepassed+time)
                {
                    d2[ngbr]=timepassed+time;
                    q.push({ngbr,2});
                }
            }
        }
        return -1;
    }
