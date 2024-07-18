// 1530. Number of Good Leaf Nodes Pairs
// LeetCode : Medium 18-07-2024

// Intution: Convert the Tree into an undirected Graph and then start DfS from all the leaf Nodes.
void makegraph(TreeNode* prev,TreeNode* root,unordered_map<TreeNode*,vector<TreeNode*>>&adj,unordered_set<TreeNode*>&leaf)
    {
        if(!root)return;
        if(!root->left  && !root->right)
        {
            leaf.insert(root);
        }
        if(prev)
        {
            adj[root].push_back(prev);
            adj[prev].push_back(root);
        }
        makegraph(root,root->left,adj,leaf);
        makegraph(root,root->right,adj,leaf);
    }
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*,vector<TreeNode*>> adj;
        unordered_set<TreeNode*> leaf;
        
        makegraph(NULL,root,adj,leaf);
        int count=0;

        for(auto &it:leaf)
        {
            queue<TreeNode* > q;
            unordered_set<TreeNode*> visited;
            q.push(it);
            visited.insert(it);
            unordered_map<TreeNode *,int> dist;
            dist[it]=0;
            while(!q.empty())
            {
                TreeNode*curr=q.front();
                q.pop();
                if(dist[curr]>distance)break;

                if(curr!=it && leaf.count(curr) && dist[curr]<=distance)
                {
                    count++;
                }
                for(auto &ngbr:adj[curr])
                {
                    if(!visited.count(ngbr))
                    {
                        visited.insert(ngbr);
                        q.push(ngbr);
                        dist[ngbr]=dist[curr]+1;
                    }
                }
            }

        }return count/2;
    }
