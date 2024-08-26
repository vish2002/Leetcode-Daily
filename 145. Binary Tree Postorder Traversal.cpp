// 145. Binary Tree Postorder Traversal
// Leetcode : Easy 25-08-2024

class Solution {
public:
    void postorder(TreeNode *root,vector<int> &ans)
    {
        if(!root)return;
        postorder(root->left,ans);
        postorder(root->right,ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root,ans);
        return ans;
    }
};
