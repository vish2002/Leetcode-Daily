// 2192. All Ancestors of a Node in a Directed Acyclic Graph
// LeetCode : Medium 29-06-2024

vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // using topological sorting
        vector<int> adj[n];
        vector<int> indegree(n,0);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0)q.push(i);
        }
        vector<int> topologicalsort(n);
        while(!q.empty())
        {
            int Node = q.front();
            q.pop();
            topologicalsort.push_back(Node);
            for(int i=0;i<adj[Node].size();i++)
            {
                indegree[adj[Node][i]]--;
                if(indegree[adj[Node][i]] == 0)q.push(adj[Node][i]);
            }
        }
        vector<vector<int>> ans(n);
        vector<set<int>> temp(n);
        for(int Node : topologicalsort)
        {
            for(int neighbour : adj[Node])
            {
                temp[neighbour].insert(Node);
                temp[neighbour].insert(temp[Node].begin(),temp[Node].end());
            }
        }
        for(int i=0;i<temp.size();i++)
        {
            ans[i].assign(temp[i].begin(),temp[i].end());
            sort(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
