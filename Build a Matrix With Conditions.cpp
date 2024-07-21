//  2392. Build a Matrix With Conditions
// LeetCode : Hard 21-07-2024


// Method 1 : Using BFS + kahns Algorithm For topological Sorting 
vector<int> topologicalsort(int k,vector<vector<int>> &edges)
    {
        // Using Kahns Algorithm for Topological sorting
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(k+1,0);
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        vector<int> toposort;
        for(int i=1;i<=k;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int Node=q.front();
            q.pop();
            toposort.push_back(Node);
            for(auto ngbr:adj[Node])
            {
                indegree[ngbr]--;
                if(indegree[ngbr]==0)
                {
                    q.push(ngbr);
                }
            }
        }
        if(toposort.size()!=k)return {};
        else return toposort;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> ans(k,vector<int>(k,0));

        vector<int> toporow=topologicalsort(k,rowConditions);
        vector<int> topocol=topologicalsort(k,colConditions);
        
        if(toporow.size() == 0 || topocol.size() == 0)
        {
            return {};
        }

        for(int i=0;i<toporow.size();i++)
        {
            for(int j=0;j<topocol.size();j++)
            {
                if(toporow[i]==topocol[j])
                {
                    ans[i][j]=toporow[i];
                }
            }
        }
        return ans;
    }
