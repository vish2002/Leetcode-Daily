// 2196. Create Binary Tree From Descriptions
// LeetCode : Medium 15-07-2024

// Intuition
// Creating the adjacency list to solve the problem.

// Approach 1
// creating an ajacency list similar to the graphs for storing the left child and the right children of a root node.
// and creating the tree from that adjacency list.

// Complexity
// Time complexity: O(n)
// Space complexity:o(n)



TreeNode* createtree(int Node, unordered_map<int, vector<int>>& adj) {
    TreeNode* root = new TreeNode(Node);
    
    if (adj.find(Node) != adj.end()) {
        if (adj[Node][0] != -1) {
            root->left = createtree(adj[Node][0], adj);
        } else {
            root->left = NULL;
        }

        if (adj[Node][1] != -1) {
            root->right = createtree(adj[Node][1], adj);
        } else {
            root->right = NULL;
        }
    }
    return root;
}

TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    unordered_map<int, vector<int>> adj;
    set<int> children;
    
    for (const auto& desc : descriptions) {
        int parent = desc[0];
        int child = desc[1];
        int isLeft = desc[2];
        
        if (adj.find(parent) == adj.end()) {
            adj[parent] = vector<int>(2, -1);
        }
        
        if (isLeft == 1) {
            adj[parent][0] = child;
        } else {
            adj[parent][1] = child;
        }
        
        children.insert(child);
    }
    
    int root = -1;
    for (const auto& desc : descriptions) {
        int parent = desc[0];
        if (children.find(parent) == children.end()) {
            root = parent;
            break;
        }
    }
    
    return createtree(root, adj);
}

// Approach 2 Without Adjacency List 

TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> s;
        unordered_map<int,TreeNode*> mp;
        for(int i=0;i<descriptions.size();i++)
        {
            int parent=descriptions[i][0];
            int child=descriptions[i][1];
            int isleft=descriptions[i][2];

            if(mp.find(parent)==mp.end())
            {
                mp[parent]=new TreeNode(parent);
            }
            if(mp.find(child)==mp.end())
            {
                mp[child]=new TreeNode(child);
            }

            if(isleft==1)
            {
                mp[parent]->left=mp[child];
            }else mp[parent]->right=mp[child];

            s.insert(child);
        }
        for(int i=0;i<descriptions.size();i++)
        {
            int parent=descriptions[i][0];
            if(s.find(parent)==s.end())
            {
                return mp[parent];
            }
        }
        return NULL;
    }
