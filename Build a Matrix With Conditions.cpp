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

// Method 2 using DFS
   void dfs(int Node,unordered_map<int,vector<int>> &adj,stack<int> &st,bool &hascycle,vector<int> &visited)
    {
        visited[Node]=1;
        for(auto ngbr:adj[Node])
        {
            if(!visited[ngbr])
            {
                dfs(ngbr,adj,st,hascycle,visited);
            }
            else if(visited[ngbr]==1)
            {
                hascycle=true;
                return;
            }
        }
        visited[Node]=2;
        st.push(Node);

    }
    vector<int> topologicalsort(int k,vector<vector<int>> &edges)
    {
        // Using DFS for topological sorting
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(k+1,0);
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        vector<int> visited(k+1,0);
        stack<int> st;
        bool hascycle=0;
        vector<int> toposort;
        for(int i=1;i<=k;i++)
        {
            if(visited[i]==0)
            {
                dfs(i,adj,st,hascycle,visited);
                if(hascycle)
                {
                    return {};
                }
            }
        }
        while(!st.empty())
        {
            toposort.push_back(st.top());
            st.pop();
        }
        return toposort;
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
