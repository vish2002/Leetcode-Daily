// 1579. Remove Max Number of Edges to Keep Graph Fully Traversable
// Leetcode : Hard 30-06-2024

class Solution {
private:
    bool check(int n, vector<int>adja[], vector<int>adjb[]){
        vector<int>visiteda(n + 1, 0);//alice's visited array
        vector<int>visitedb(n + 1, 0);//bob's visited array
        queue<int>q;
        int start = 1;
        visiteda[start] = 1;
        visitedb[start] = 1;

        //perform simple bfs traversal for traversability on the graph
        q.push(start);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adja[node]){
                if(!visiteda[it]){
                    visiteda[it] = 1;
                    q.push(it);
                }
            }
        }
        q.push(start);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adjb[node]){
                if(!visitedb[it]){
                    visitedb[it] = 1;
                    q.push(it);
                }
            }
        }
        for(int i = 1; i<=n; i++){
            if(!visiteda[i] || !visitedb[i]){
                return false;
            }
        }
        return true;
    }
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        //alice can use type 1 + type 3
        //bob can use type 1 + type 2
        vector<int>adja[n + 1];//type 1 + type 3
        vector<int>adjb[n + 1];//type 2 + type 3
        vector<int>adj[n + 1];//type 3 only, we'll need it later
        for(auto it : edges){
            if(it[0] == 1 || it[0] == 3){
                adja[it[1]].push_back(it[2]);
                adja[it[2]].push_back(it[1]);
            }
            if(it[0] == 2 || it[0] == 3){
                adjb[it[1]].push_back(it[2]);
                adjb[it[2]].push_back(it[1]);
            }
            if(it[0] == 3){
                adj[it[1]].push_back(it[2]);
                adj[it[2]].push_back(it[1]);
            }
        }
        //check if graph is traversable
        if(!check(n, adja, adjb)){
            return -1;
        }
        int ans = 0;
        //find number of components of the graph, where each component is made using "type 3" edges alone.

        //for internal connections, we need only v - 1 vertices, where v is the number of vertices in the component. Remove all extra edges.
        //for external connections ( connection between components), we need 2 edges only, one each from type 1 and type 2. Remove all extra edges.
        //so, number of edges needed for external connection = 2 * (number of components - 1)
        vector<int>visited(n + 1, 0);
        vector<vector<int>>components;
        for(int i = 1; i<=n; i++){
            if(!visited[i]){
                vector<int>temp;
                queue<int>q;
                q.push(i);
                visited[i] = 1;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    temp.push_back(node);
                    for(auto it : adj[node]){
                        if(!visited[it]){
                            visited[it] = 1;
                            q.push(it);
                        }
                    }
                }
                components.push_back(temp);
            }
        }
        int needed_edges = 0;
        for(auto it : components){
            //adding v - 1 for each component (internal connection)
            needed_edges += it.size() - 1;
        }
        //adding 2 * (number of components - 1) for external connections.
        needed_edges += (components.size() - 1)*2;
        ans = edges.size() - needed_edges;
        return ans;
    }
};
