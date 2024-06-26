
//Convert BST To Balanced BST
// Leetcode : Medium 26-06-24

void inorder(TreeNode* root,vector<int> &ans)
    {
        if(!root)return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    TreeNode*balancedBST(vector<int> ans)
    {
        if(ans.empty())return nullptr;
        int mid=ans.size()/2;
        TreeNode*root=new TreeNode(ans[mid]);
        root->left=balancedBST(vector<int>(begin(ans),begin(ans)+mid));
        root->right=balancedBST(vector<int>(begin(ans)+mid+1,end(ans)));
        return root;

    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        return balancedBST(ans);
    }
